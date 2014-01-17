#include <new>
#include <map>
#include <queue>
#include <cstring>
#include <fstream>

#include "tileset.h"
#include "vector2d.h"
#include "direction.h"

#define NB_CASE_X_VIEW 6
#define NB_CASE_Y_VIEW 4


using namespace std;

typedef struct
{
	sf::VertexArray vertices;
	sf::Texture* texture;
}VertexArrayOnTexture;

class Map;

class Case
{
public:

	//ctor
	Case::Case(){}

	Case::Case(const Point2i &p1,
				const Point2i &p2,
				const Point2i &p3,
				const Point2i &p4,
				,const bool & practic
				, const bool & gauche, const bool & droite, const bool & haut, const bool & bas
				, const unsigned int & evenement, const unsigned int & autoEvenement):
				couches[0](p1),couches[1](p2),couches[2](p3),couches[3](p4)
				,event(evenement),autoEvenement(autoEvenement)
				,practicable(practic),mvtDir[Gauche](gauche),mvtDir[Droite](droite),mvtDir[Haut](haut),mvtDir[Bas](bas)
	{
		for(unsigned int i =0;i<4;i++)
		{
			if(couches[i]==Point2i()){couchesExist[i]=false;}
			else{couchesExist[i]=true;}
		}
		if(evenement == 0){eventExist=false;}
		else{eventExist=true;}
	}

	bool Case::GetPracticable() const
	{
	return practicable;
	}

	bool Case::canDirection(const Direction & d) const
	{
		return mvtDir[d];

	}

	Point2i Case::GetTilesetPos(const unsigned int & couche) const
	{
		if(couche>3){return EXIT_FAILURE}
		return couches[couche];
	}

	bool Case::GetCoucheExist(const unsigned int & couche) const
	{
		if(couche>3){return false;}
		else{return couchesExist[couche];}
	}

protected:
	
	friend Map;
	
	VertexArrayOnTexture vertexArray[6];

private:

	Point2i couches[4];
	bool couchesExist[4];
	

	Evenement event;
	bool eventExist;

	Evenement autoEvent;
	bool autoEventExist;

	bool practicable;
	bool mvtDir[4];
};




class Map
{
public:

Map::Map(const string & filePath)
{
	LoadFromFile(filePath);
	_emptySprite.setTexture(_backgroundTexture);
	_emptySprite.setTextureRect(0.f,0.f,0.f,0.f);
	_emptySprite.setPosition(0,0);
	updateSprites();
}

Map::~Map()
{
	for(unsigned int i = 0;i<_width;i++)
	{
		delete _cases[i];
	}
	delete _cases;
}

bool Map::GetDirectionAndPracticableGrid_from_pos(const Direction & d1, const Point2f & pos,const float & radius) const
{
	bool practic(true);
	for(unsigned int i = static_cast<int>(pos.x-radius);i<=static_cast<int>(pos.x+radius);i++)
	{
		for(unsigned int j = static_cast<int>(pos.y-radius);j<=static_cast<int>(pos.y+radius);j++)
		{
			practic =(_cases[i][j].canDirection(d1)
				&&GetCase(Point2i(i,j).addDirection(d1)).canDirection(directionOpposee(d1))
				&&GetPracticable(Point2i(i,j).addDirection(d1))
				&&GetPracticable(Point2i(i,j).addDirection(d1)));

			if(!practic)){break;}
		}
	}

	return practic;
}

void Map::LoadFromFile(const string & filePath)
{
	string backgroundName;

	ifstream mapFile;
	mapFile.open(filePath);

	mapFile>>_noMap;
	mapFile>>_nameOfMap;
	mapFile>>_dateOfCreation;
	mapFile>>_madeBy;

	mapFile>>_typeOf;
	mapFile>>_tileSetName;

	mapFile>>_height;
	mapFile>>_width;

	mapFile>>backgroundName;
	if(!_backgroundTexture.LoadFromFile("rsc/img/panoramas/"+backgroundName".png"))
	{
		if(!_backgroundTexture.LoadFromFile("rsc/img/panoramas/black.png"))
		{
			cout<<"ERROR WITH :Background texture : "+backgroundName+".png NOT FOUND"<<endl;
			return EXIT_FAILURE;
		}
	}


	_tileset = Tileset(_typeOf,_tileSetName);

	_cases = new Case*[_width];
	for(unsigned int i = 0;i<_width;i++)
	{
		_cases[i]=new Case[_height];
	}

	Point2i p1,p2,p3,p4;
	unsigned int evenement;
	bool practic,mvG,mvD,mvH,mvB;

	for(unsigned int i = 0;i<_width;i++)
	{
		for(unsigned int j = 0; j<_height;j++)
		{
			mapFile>>p1.x;
			mapFile>>p1.y;
			mapFile>>p2.x;
			mapFile>>p2.y;
			mapFile>>p3.x;
			mapFile>>p3.y;
			mapFile>>p4.x;
			mapFile>>p4.y;
			mapFile>>evenement;


			TilesetCase t;
			if(p1!=Point2i())
				{t= _tileset.GetTilesetCase(p1);  }
			if(p2!=Point2i())
				{t= _tileset.GetTilesetCase(p2);  }
			if(p3!=Point2i())
				{t= _tileset.GetTilesetCase(p3);  }
			if(p4!=Point2i())
				{t= _tileset.GetTilesetCase(p4);  }

			_cases[i][j]=Case(p1,p2,p3,p4,t.practic,t.mvG,t.mvD,t.mvH,t.mvB,evenement,t.autoEvent);
		}
	}
	mapFile.close();
}

void Map::updateSprites()
{


	
	for(unsigned int sup = 0 ; sup<6 ; sup++)
	{
		for(unsigned int x = 0 ; x<_width ; x++)
		{
			for(unsigned int y = 0 ; y<_height ; y++)
			{
				_cases[x][y].vertexArray[sup].vertices.clear();
				_cases[x][y].vertexArray[sup].texture = NULL;
			}
		}
	}
    
    
	for(unsigned int i = 0;i<_width;i++)
    {
        for( unsigned int j = 0; j<_height;j++)
        {
            for(unsigned int c = 0 ; c<5 ; c++)
			{
                if(_cases[i][j].GetCoucheExist(c))
                {
					unsigned int super = _tileset.GetTilesetCase(tilesetPosition).superpositionPriority;
                    if(_cases[i][j].GetTilesetPos(c).y==0)
					{
						if(_tileset.GetAutotileExist(_cases[i][j].GetTilesetPos(c)))
						{	
							Point2i tilesetPosition = _cases[i][j].GetTilesetPos(c);
							_tileset.GetAutotile(tilesetPosition)->GetSprites((_cases[i-1][j-1].GetTilesetPos(c)==tilesetPosition),(_cases[i  ][j-1].GetTilesetPos(c)==tilesetPosition),(_cases[i+1][j-1].GetTilesetPos(c)==tilesetPosition),
																			  (_cases[i-1][j  ].GetTilesetPos(c)==tilesetPosition),														(_cases[i+1][j  ].GetTilesetPos(c)==tilesetPosition),
																			  (_cases[i-1][j+1].GetTilesetPos(c)==tilesetPosition),(_cases[i  ][j+1].GetTilesetPos(c)==tilesetPosition),(_cases[i+1][j+1].GetTilesetPos(c)==tilesetPosition),
																			  Point2i(i,j),_cases[i][j].vertexArray[super].vertices);
							_cases[i][j].vertexArray[super].texture = _tileset.GetAutotile(tilesetPosition).GetTexture();
						}
					}
                    else
                    {
                        sfUse::Sprite2VertexArray(GetSprite(i,j,c),_cases[i][j].vertexArray[super].vertices);
						_cases[i][j].vertexArray[super].texture = _tileset.GetTexture();
                    }
                }
			}
        }
    }
	
	
}

Evenement Map::GetEvent(const Point2i & p) const
{

}

Case Map::GetCase(const Point2i & p) const
{
	return _cases[p.x][p.y];
}

Tileset Map::GetTileset() const
{
	return _tileset;
}

bool Map::GetPracticable(const Point2i & p) const
{
	return _cases[p.x][p.y].GetPracticable();
}

sf::Sprite Map::GetSprite(const unsigned int x, const unsigned int y,const unsigned int & couche) const
{
	if(_cases[p.x][p.y].GetCoucheExist(couche))
	{
		_sprite = _tileset.GetSprite(_cases[x][y].GetTilesetPos(couche));
		_sprite.setPosition(x*64,y*64);
		_sprite.setScale(64/_sprite.getSize().x,64/_sprite.getSize().y);
		return _sprite;
	}
	else{return _emptySprite;}
}

sf::Sprite Map::GetSprite(const Point2i & p,const unsigned int & couche) const
{
	return GetSprite(p.x,p.y,couche);
}


/*
map<Point2f,Item*> Items_on_map;
map<Point2f,Item*>iterator it_Items_on_map;
pair<map<Point2f,Item*>iterator,bool> ret_Items_on_map;

void Map::pushOut(Item* objectToPush,const Point2f & p)
{
	ret_Items_on_map=Items_on_map.insert( pair<Point2f,Item>(p,objectToPush));
	if (!ret_Items_on_map.second)
	{
			Point2f a(0.001,0.0);
			Point2f b(0.0,0.001);
			Point2f actA(0.0,0.0);
			Point2f actB(0.0,0.0);
			while(!ret_Items_on_map.second)
			{
				actA += a;
				actB += b;
				if(getPracticableFromPoint(Point2i(p+actA))){ret_Items_on_map=Items_on_map.insert( pair<Point2f,Item*>(p+actA,objectToPush));}
				if((!ret_Items_on_map.second)&&(getPracticableFromPoint(Point2i(p+actB)))){ret_Items_on_map=Items_on_map.insert( pair<Point2f,Item*>(p+actB,objectToPush));}
				if((!ret_Items_on_map.second)&&(getPracticableFromPoint(Point2i(p-actA)))){ret_Items_on_map=Items_on_map.insert( pair<Point2f,Item*>(p-actA,objectToPush));}
				if((!ret_Items_on_map.second)&&(getPracticableFromPoint(Point2i(p-actB)))){ret_Items_on_map=Items_on_map.insert( pair<Point2f,Item*>(p-actB,objectToPush));}
			}
	}
}
*/

void Map::draw(sf::RenderWindow & window, priority_queue<Character> charactersOrderedByPosition,const Point2i & center)
{
	int cXt=center.x-NB_CASE_X_VIEW
	,cYt=center.y-NB_CASE_Y_VIEW;
	if(cXt<=0){cXt=0;}
	if(cYt<=0){cYt=0;}
	cXb=cXt+2*NB_CASE_X_VIEW;
	cYb=cYb+2*NB_CASE_Y_VIEW;
	if(cXb>_width ){cXb=_width;cXt=cXb-2*NB_CASE_X_VIEW;}
	if(cYb>_height){cYb=_height;cYt=cYb-2*NB_CASE_Y_VIEW;}

	if(_emptySprite.getTexture() != NULL)
	{
		_emptySprite.setTextureRect(0.f,0.f,(float)window.getWidth(),(float)window.getHeight());
		window.draw(_emptySprite);
		_emptySprite.setTextureRect(0.f,0.f,0.f,0.f);
	}

	for(unsigned int i=cXt ; i<cXb ; i++)
	{
		for(unsigned int j=cYt ; j<cYb ; j++)
		{
			if(_cases[i][j].vertexArray[0].texture != NULL)
			{
			window.draw(_cases[i][j].vertexArray[0].vertices,_cases[i][j].vertexArray[0].texture);
			}
		}
	}

	for(unsigned int i=cXt ; i<cXb ; i++)
	{
		for(unsigned int j=cYt ; j<cYb ; j++)
		{
			while( Point2i(i,j) == ( charactersOrderedByPosition.top().GetPositionI() ) )
			{
				window.draw(charactersOrderedByPosition.top().GetSprite());
				charactersOrderedByPosition.pop();
			}
			if(_cases[i][j].vertexArray[1].texture != NULL)
			{
				window.draw(_cases[i][j].vertexArray[1].vertices,_cases[i][j].vertexArray[1].texture);
			}
		}
	}

for(unsigned int s = 2; s<6 ; s++)
{
	for(unsigned int i=cXt ; i<cXb ; i++)
	{
		for(unsigned int j=cYt ; j<cYb ; j++)
		{
			if(_cases[i][j].vertexArray[s].texture != NULL)
			{
				window.draw(_cases[i][j].vertexArray[s].vertices,_cases[i][j].vertexArray[s].texture);
			}
		}
	}
}

}

private:


	unsigned int _noMap;
	String _dateOfCreation;
	String _nameOfMap;
	String _madeBy;

	unsigned int _typeOf;
	string _tileSetName;
	Tileset _tileset;

	unsigned int _height;
	unsigned int _width;
	Case** _cases;

	sf::Vector2f _resolution;

	sf::Texture _backgroundTexture;
	sf::Sprite _emptySprite;
	sf::Sprite _sprite;
};

