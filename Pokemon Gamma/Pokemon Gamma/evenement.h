//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Garazbolg 28/01/2014															//
//																																		//
//														Evenement.h																		//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <SFML/Graphics.hpp>

#include "vector2d.h"
#include "direction.h"


enum TypeTrigger{Action,Auto,ContactHeros,ContactEvent,ParalleleProcess};

class Evenement : public sf::Drawable
{

public :

	Evenement(const std::string & filePath,const Point2i & pos);
	bool move(const Direction & d);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

protected :

	Point2i position;
	TypeTrigger trigger;
	bool animated;
	bool animatedInStop;
	sf::Texture image;
	sf::Sprite sprite;
	Map* map;

};
