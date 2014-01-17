//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Garazbolg 18/01/2013															//
//																																		//
//														Autotiles																		//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef AUTOTILES_H
#define AUTOTILES_H

//autotiles

#include "vector2d.h"
#include <SFML/graphics.hpp>

/*
	Autotiles works like in RPGMaker XP
*/

class Autotile
{
public:

	Autotile(const std::string & fileName);

    sf::Texture* GetTexture();

	void GetSprites( const bool & c00,const bool & c10,const bool & c20,
                     const bool & c01				  ,const bool & c21,
                     const bool & c02,const bool & c12,const bool & c22,const Point2i & position,sf::VertexArray & );

private:

	unsigned int _resolution;
	float _scale;
	unsigned int _semiResolution;
	sf::Texture _image;
	sf::Sprite _sprite[4];

};

#endif
