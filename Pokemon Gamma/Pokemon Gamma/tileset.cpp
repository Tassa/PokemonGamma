//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Garazbolg 18/01/2013															//
//																																		//
//														Tileset																			//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <new>
#include <string>
#include "vector2d.h"
#include "autotiles.h"
#include "usefullGeneralThings.h"
#include "tileset.h"

TilesetCase::TilesetCase(){}

TilesetCase::TilesetCase(	const bool &practicable,
							const bool &mG,const bool &mD,const bool &mH,const bool &mB,
							const unsigned int &autoEvenement,
							const unsigned int &superposition)
{
	practic = practicable;
	mvG = mG;
	mvD = mD;
	mvH = mH;
	mvB = mB;
	autoEvent = autoEvenement;
	superpositionPriority = superposition;
}


void Tileset::LoadTextureFromFile(const std::string & tilesetName)
{
	if(!_TilesetTexture.loadFromFile("Graphics/Tilesets/"+tilesetName+".png"))
	{
		std::cout<<"ERROR WITH : Tileset "+tilesetName+".png NOT FOUND"<<std::endl;
		exit(0);
	}
	_resolution = _TilesetTexture.getSize().x/WIDTH_OF_TILESET;
	_height = (_TilesetTexture.getSize().y/_resolution)+1;
}

void Tileset::LoadDataFromFile(const std::string & tilesetName)
{
	std::ifstream tilesetFile;
	tilesetFile.open("Data/Tilesets/"+tilesetName+".til"); // Pas dans la version finale, mais pour les premiers tests
	
	std::string pictureName;
	tilesetFile>>pictureName;
	LoadTextureFromFile(pictureName);
	
	std::string autotilesFilePath;
	for(unsigned int a = 0; a<MAX_AUTOTILES_PER_TILESET ; a++)
	{
		tilesetFile>>autotilesFilePath;
		if(autotilesFilePath != "N/A")
		{
			autotiles[a] = Autotile(autotilesFilePath);
			autotilesExist[a] = true;
		}
		else
		{
			autotilesExist[a] = false;
		}
	}
		
	_cases = new TilesetCase*[WIDTH_OF_TILESET];
	for(unsigned int i =0;i<WIDTH_OF_TILESET;i++)
	{
		_cases[i]=new TilesetCase[_height];
	}
		

	unsigned int autoEvent,superpositionPriority;
	bool practic,mvG,mvD,mvH,mvB;

	for(unsigned int i = 0;i<WIDTH_OF_TILESET;i++)
	{
		for(unsigned int j = 0; j<_height+1;j++)
		{

			tilesetFile >> std::boolalpha >>practic;
			tilesetFile >> std::boolalpha >> mvG;
			tilesetFile >> std::boolalpha >> mvD;
			tilesetFile >> std::boolalpha >> mvH;
			tilesetFile >> std::boolalpha >> mvB;
			tilesetFile>>autoEvent;
			tilesetFile>>superpositionPriority;
			_cases[i][j]=TilesetCase(practic,mvG,mvD,mvH,mvB,autoEvent,superpositionPriority);
		}
	}
	tilesetFile.close();
}

void Tileset::init(const std::string & name)
{
	_name = name;
	
	LoadDataFromFile(name);
	_sprite.setTexture(_TilesetTexture);
	_sprite.setScale(64.f/_resolution,64.f/_resolution);
}

Tileset::~Tileset()
{
	for (unsigned int i = 0; i<WIDTH_OF_TILESET; i++)
	{
		delete _cases[i];
	}
	delete _cases;
}
sf::Sprite Tileset::GetSprite(const unsigned int & x,const unsigned int & y)
{
	_sprite.setTextureRect(sf::IntRect(x*_resolution,(y-1)*_resolution,_resolution,_resolution));		//y-1 because of the autotiles
	return _sprite;
}

sf::Sprite Tileset::GetSprite(const Point2i & p)
{
	return GetSprite(p.x,p.y);
}

Autotile * Tileset::GetAutotile(const Point2i & p)
{
	return autotiles+(p.x-1);
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

sf::Texture* Tileset::GetTexture()
{
	return &_TilesetTexture;
}
