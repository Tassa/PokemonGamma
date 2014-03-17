//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Garazbolg 18/01/2013															//
//																																		//
//														Evenement																		//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <SFML/Graphics.hpp>

#include "vector2d.h"
#include "direction.h"
#include "map.h"
#include "evenement.h"

namespace MapEngine
{

	Evenement::Evenement(const char * filePath, const Point2i & pos, Map * m) : position(pos)
	{
		map = m;
		image.loadFromFile(filePath);
		sprite.setTexture(image);
		sprite.setTextureRect(sf::IntRect(0, 0, (int)image.getSize().x / 4, (int)image.getSize().y / 4));
		sprite.setPosition(position*64.f);																	///// Escaliers !!!
	}

	bool Evenement::move(const Direction & d)
	{
		if (map->CanMove(d, position))
		{
			position.addDirection(d);
			sprite.setPosition(position*64.f);
			return true;
		}
		else
		{
			return false;
		}
	}


	void Evenement::draw(sf::RenderTarget &target, sf::RenderStates states) const
	{
		target.draw(sprite, states);
	}

	Point2i Evenement::getPosition() const
	{
		return position;
	}

	bool Evenement::operator<(const Evenement &a1) const
	{
		//On renvoie 0 ou 1 selon que la comparaison est  
		//vraie ou fausse  
		return (getPosition() < a1.getPosition());
	}
}