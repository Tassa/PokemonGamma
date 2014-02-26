//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Garazbolg 18/01/2013															//
//																																		//
//														Map																				//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <new>
#include <map>
#include <queue>
#include <cstring>
#include <fstream>
#include <iostream>

#include "tileset.h"
#include "vector2d.h"
#include "direction.h"
#include "usefullSFMLThings.h"
#include "map.h"

	//ctor
Case::Case(){}

void Case::init(const Point2i * positions,
			const bool & practic,
			const bool & gauche, const bool & droite, const bool & haut, const bool & bas,
			const unsigned int & autoEvenement)
{
	for (int i = 0; i < NB_COUCHES; i++)
		couches[i] = positions[i];

		/*
		event(evenement);
		autoEvenement(autoEvenement)
		*/
	practicable = practic;
	mvtDir[Gauche] = gauche;
	mvtDir[Droite] = droite;
	mvtDir[Haut] = haut;
	mvtDir[Bas] = bas;

	for(unsigned int i =0;i<4;i++)
	{
		if(couches[i]==Point2i()){couchesExist[i]=false;}
		else{couchesExist[i]=true;}
	}
	/*if(evenement == 0){eventExist=false;}
	else{eventExist=true;}*/
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
	if (couche > NB_COUCHES ){ exit(3); }
	return couches[couche];
}

bool Case::GetCoucheExist(const unsigned int & couche) const
{
	if (couche > NB_COUCHES ){return false;}
	else{return couchesExist[couche];}
}


Map::Map(const std::string & filePath)
{
	LoadFromFile(filePath);
	_emptySprite.setTexture(_backgroundTexture);
	_emptySprite.setTextureRect(sf::IntRect(0,0,0,0));
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

bool Map::CanMove(const Direction & d1, const Point2i & pos) const
{

	return (_cases[pos.x][pos.y].canDirection(d1)
			&& GetCase(pos.addDirection(d1)).canDirection(directionOpposee(d1))
			&& GetPracticable(pos.addDirection(d1)));

}

void Map::LoadFromFile(const std::string & filePath)
{
	std::string backgroundName;

	std::ifstream mapFile;
	mapFile.open(filePath);

	//mapFile>>_noMap;
	mapFile>>_nameOfMap;
	mapFile>>_tileSetName;

	mapFile>>_height;
	mapFile>>_width;

	//mapFile>>backgroundName;
	if(!_backgroundTexture.loadFromFile("Graphics/Panoramas/"+backgroundName+".png"))
	{
		if (!_backgroundTexture.loadFromFile("Graphics/Panoramas/black.png"))
		{
			std::cout<<"ERROR WITH :Background texture : "+backgroundName+".png NOT FOUND"<<std::endl;
			exit(1);
		}
	}


	_tileset.init(_tileSetName);

	_cases = new Case*[_width];
	for(unsigned int i = 0;i<_width;i++)
	{
		_cases[i]=new Case[_height];
	}

	Point2i positions[NB_COUCHES];
	unsigned int evenement;

	for(unsigned int i = 0;i<_width;i++)
	{
		for(unsigned int j = 0; j<_height;j++)
		{
			for (unsigned int k; k < NB_COUCHES; k++)
			{
				mapFile >> positions[k].x;
				mapFile >> positions[k].y;
			}
			


			TilesetCase t;
			for (unsigned int k; k < NB_COUCHES; k++)
			{
				if ((positions[k] != Point2i()) && (_tileset.GetTilesetCase(positions[k]).superpositionPriority < 2))
				{
					t = _tileset.GetTilesetCase(positions[k]);
				}
			}


			_cases[i][j].init(positions,t.practic,t.mvG,t.mvD,t.mvH,t.mvB,t.autoEvent);
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
					Point2i tilesetPosition = _cases[i][j].GetTilesetPos(c);
					unsigned int super = _tileset.GetTilesetCase(tilesetPosition).superpositionPriority;
                    if(_cases[i][j].GetTilesetPos(c).y==0)
					{
						if(_tileset.GetAutotileExist(_cases[i][j].GetTilesetPos(c)))
						{	
							
							_tileset.GetAutotile(tilesetPosition)->GetSprites((_cases[i-1][j-1].GetTilesetPos(c)==tilesetPosition),(_cases[i  ][j-1].GetTilesetPos(c)==tilesetPosition),(_cases[i+1][j-1].GetTilesetPos(c)==tilesetPosition),
																			  (_cases[i-1][j  ].GetTilesetPos(c)==tilesetPosition),														(_cases[i+1][j  ].GetTilesetPos(c)==tilesetPosition),
																			  (_cases[i-1][j+1].GetTilesetPos(c)==tilesetPosition),(_cases[i  ][j+1].GetTilesetPos(c)==tilesetPosition),(_cases[i+1][j+1].GetTilesetPos(c)==tilesetPosition),
																			  Point2i(i,j),_cases[i][j].vertexArray[super].vertices);
							_cases[i][j].vertexArray[super].texture = _tileset.GetAutotile(tilesetPosition)->GetTexture();
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

Case Map::GetCase(const Point2i & p) const
{
	return _cases[p.x][p.y];
}

Tileset * Map::GetTileset()
{
	return (&_tileset);
}

bool Map::GetPracticable(const Point2i & p) const
{
	return _cases[p.x][p.y].GetPracticable();
}

sf::Sprite Map::GetSprite(const unsigned int x, const unsigned int y,const unsigned int & couche)
{
	if(_cases[x][y].GetCoucheExist(couche))
	{
		_sprite = _tileset.GetSprite(_cases[x][y].GetTilesetPos(couche));
		_sprite.setPosition(64.f*x, 64.f*y);
		//_sprite.setScale(64/_sprite.getSize().x,64/_sprite.getSize().y);
		return _sprite;
	}
	else{return _emptySprite;}
}

sf::Sprite Map::GetSprite(const Point2i & p,const unsigned int & couche)
{
	return GetSprite(p.x,p.y,couche);
}


void Map::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	int cXt=mainEvent->getPosition().x-NB_CASE_X_VIEW
		, cYt = mainEvent->getPosition().y - NB_CASE_Y_VIEW;
	if(cXt<=0){cXt=0;}
	if(cYt<=0){cYt=0;}
	int cXb=cXt+2*NB_CASE_X_VIEW,
	cYb=cYt+2*NB_CASE_Y_VIEW;
	if((unsigned int)cXb>_width ){cXb=_width;cXt=cXb-2*NB_CASE_X_VIEW;}
	if((unsigned int)cYb>_height){cYb=_height;cYt=cYb-2*NB_CASE_Y_VIEW;} /// Map link ?

	std::priority_queue<Evenement> tampon;

	for (unsigned int k = 0; k < eventsOnMap.size(); k++)
	{
		tampon.push(eventsOnMap[k]);
	}
	for (unsigned int k = 0; k < otherEvents.size(); k++)
	{
		tampon.push(*otherEvents[k]);
	}

	/*if(_emptySprite.getTexture() != NULL)
	{
		_emptySprite.setTextureRect(sf::IntRect(0,0,(int)target.getSize().x,(int)target.getSize().y));
		target.draw(_emptySprite);
	}*/

	for(int i=cXt ; i<cXb ; i++)
	{
		for(int j=cYt ; j<cYb ; j++)
		{
			if(_cases[i][j].vertexArray[0].texture != NULL)
			{
			target.draw(_cases[i][j].vertexArray[0].vertices,_cases[i][j].vertexArray[0].texture);
			}
		}
	}

	for(int i=cXt ; i<cXb ; i++)
	{
		for(int j=cYt ; j<cYb ; j++)
		{
			while((!tampon.empty())&&( Point2i(i,j) == ( tampon.top().getPosition())))
			{
				target.draw(tampon.top());
			}
			if(_cases[i][j].vertexArray[1].texture != NULL)
			{
				target.draw(_cases[i][j].vertexArray[1].vertices,_cases[i][j].vertexArray[1].texture);
			}
		}
	}

	for(int s = 2; s<6 ; s++)
	{
		for(int i=cXt ; i<cXb ; i++)
		{
			for(int j=cYt ; j<cYb ; j++)
			{
				if(_cases[i][j].vertexArray[s].texture != NULL)
				{
					target.draw(_cases[i][j].vertexArray[s].vertices,_cases[i][j].vertexArray[s].texture);
				}
			}
		}
	}

}


bool Map::setMainEvent(Evenement * event)
{
	for (std::vector<Evenement *>::iterator it = otherEvents.begin(); it != otherEvents.end(); ++it)
	{
		if (*it == event){ mainEvent = event; return true; }
	}
	
	return false;
}

bool Map::addEvent(Evenement * event)
{
	for (std::vector<Evenement *>::iterator it = otherEvents.begin(); it != otherEvents.end(); ++it)
	{
		if (*it == event){ return false; }
	}
	otherEvents.push_back(event);
	return true;
}