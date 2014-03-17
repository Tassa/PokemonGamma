//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Garazbolg 18/01/2013															//
//																																		//
//														main																			//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <SFML/Graphics.hpp>
#include "map.h"
#include "evenement.h"


void main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	MapEngine::Map* theMap = new MapEngine::Map("Map/testPokemon.map");
	MapEngine::Evenement * mainEvent = new MapEngine::Evenement("rsc/perso.png", MapEngine::Point2i(10, 6), theMap);
	theMap->addEvent(mainEvent);
	theMap->setMainEvent(mainEvent);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			window.close();
		}
		window.clear();
		window.draw(*theMap);
		window.display();
	}
}
