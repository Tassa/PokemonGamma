#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <new>
#include "usefullGeneralThings.h"


#define MAX_TYPE_TILESET 5
#define MAX_DIF_TILESET_PER_TYPE 20
#define MAX_AUTOTILES_PER_TILESET 7

const std::string typesTilesetNames[MAX_TYPE_TILESET]={"City","Mine","Forest","Field","Dungeon"};

class TilesetCase
{
	public:

		TilesetCase::TilesetCase(){}

		TilesetCase::TilesetCase(	const bool &practicable,
									const bool &mG,const bool &mD,const bool &mH,const bool &mB,
									const unsigned int &autoEvenement,
									const unsigned int &superposition):
									practic(practicable),mvG(mG),mvD(mD),mvH(mH),mvB(mB),autoEvent(autoEvenement),superpositionPriority(superposition)
		{}

		const unsigned int autoEvent,superpositionPriority;
		const bool practic,mvG,mvD,mvH,mvB;

};

class Tileset
{
public:

	void Tileset::LoadTextureFromFile(const string & tilesetName)
	{
		if(!_TilesetTexture.LoadFromFile("rsc/img/Tilesets/"+typesTilesetNames[_type]+"/"+tilesetName+".png"))
		{
			std::cout<<"ERROR WITH : Tileset "+typesTilesetNames[_type]+"/"+tilesetName+".png NOT FOUND"<<endl;
			return EXIT_FAILURE;
		}
		_resolution = _TilesetTexture.GetWidth()/_width;
		_height = (_TilesetTexture.GetHeight()/_resolution)+1;
	}

	void Tileset::LoadDataFromFile(const string & tilesetName)
	{
		ifstream tilesetFile;
		tilesetFile.open("rsc/data/Tilesets/"+typesTilesetNames[_type]+"/"+tilesetName+".til");

		tilesetFile>>_dateOfCreation;
		
		string pictureName;
		tilesetFile>>pictureName;
		LoadTextureFromFile(pictureName);
		
		string autotilesFilePath;
		for(unsigned int a = 0; a<MAX_AUTOTILES_PER_TILESET ; a++)
		{
			tilesetFile>>autotilesFilePath;
			if(autotilesFilePath != "N/A")
			{
				autotiles[a] = Autotile(autotilesFilePath);
				autotilesExist=true;
			}
			else
			{
				autotilesExist=false;
			}
		}
		
		_cases = new TilesetCase*[_width];
		for(unsigned int i =0;i<_width;i++)
		{
			_cases[i]=new TilesetCase[_height];
		}
		

		unsigned int autoEvent,superpositionPriority;
		bool practic,mvG,mvD,mvH,mvB;

		for(unsigned int i = 0;i<_width;i++)
		{
			for(unsigned int j = 0; j<_height+1;j++)
			{

				tilesetFile>>boolalpha>>practic;
				tilesetFile>>boolalpha>>mvG;
				tilesetFile>>boolalpha>>mvD;
				tilesetFile>>boolalpha>>mvH;
				tilesetFile>>boolalpha>>mvB;
				tilesetFile>>autoEvent;
				tilesetFile>>superpositionPriority;

				_cases[i][j]=TilesetCase(practic,mvG,mvD,mvH,mvB,autoEvent,superpositionPriority);
			}
		}

		tilesetFile.close();

	}

	Tileset::Tileset(const unsigned int & type, const string & name)
	{
		_type = type;
		_name = name;
		_width = 8;
		
		LoadDataFromFile(name);
		_sprite.setTexture(_TilesetTexture);
		_sprite.setScale(64.f/_resolution,64.f/_resolution);
	}

	Tileset::~Tileset()
	{
		for(unsigned int i =0;i<_width;i++)
		{
			delete _cases[i];
		}
		delete _cases;
	}

	sf::Sprite Tileset::GetSprite(const unsigned int & x,const unsigned int & y) const
	{
		_sprite.setTextureRect(sf::IntRect(x*_resolution,(y-1)*_resolution,_resolution,_resolution));//y-1 because of the autotiles
		return _sprite;
	}

	sf::Sprite Tileset::GetSprite(const Point2i & p) const
	{
		return GetSprite(p.x,p.y);
	}

	Autotile* Tileset::GetAutotile(const Point2i & p) const
	{
		return &autotiles[p.x-1];
	}
	
	bool Tileset::GetAutotileExist(const Point2i & p) const
	{
		return autotilesExist[p.x-1];
	}
	
	TilesetCase Tileset::GetTilesetCase(const unsigned int & x,const unsigned int & y) const
	{
		return _cases[x][y];
	}

	TilesetCase Tileset::GetTilesetCase(const Point2i & p) const
	{
		return GetTilesetCase(p.x,p.y);
	}

	sf::Texture Tileset::GetTexture()
	{
		return &_TilesetTexture;
	}


private:

	sf::Texture _TilesetTexture;
	sf::Sprite _sprite;
	TilesetCase** _cases;
	Autotile autotiles[MAX_AUTOTILES_PER_TILESET];
	bool autotilesExist[MAX_AUTOTILES_PER_TILESET];
	unsigned int _width;
	unsigned int _height;
	unsigned int _resolution;
	unsigned int _type;
	std::string _name;

};
