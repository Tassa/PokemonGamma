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

Evenement::Evenement(const std::string & filePath, const Point2i & pos) : position(pos)
{
	image.loadFromFile(filePath);
	sprite.setTexture(image);
	sprite.setTextureRect(sf::IntRect(0, 0, (int)image.getSize().x / 4, (int)image.getSize().y / 4));
	sprite.setPosition(position*64.f);
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