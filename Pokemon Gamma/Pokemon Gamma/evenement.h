//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Garazbolg 28/01/2014															//
//																																		//
//														Evenement.h																		//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <SFML/Graphics.hpp>

#include "vector2d.h"
#include "direction.h"
//#include "map.h"

namespace MapEngine
{

	enum TypeTrigger{ Action, Auto, ContactHeros, ContactEvent, ParalleleProcess };

	class Map;

	class Evenement : public sf::Drawable
	{

	public:

		Evenement(const char * filePath, const Point2i & pos, Map * m);
		bool move(const Direction & d);
		void draw(sf::RenderTarget &target, sf::RenderStates states) const;
		Point2i getPosition() const;
		bool operator<(const Evenement &a1) const;

	protected:

		Point2i position;
		TypeTrigger trigger;
		bool animated;
		bool animatedInStop;
		sf::Texture image;
		sf::Sprite sprite;
		Map* map;

	};
}
#endif