//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Garazbolg 18/01/2013															//
//																																		//
//														mainMap																			//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include "map.h"
#include "evenement.h"

void run()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	Map* theMap = new Map("Map/testPokemon.map");
	Evenement mainEvent("rsc/perso.png",Point2i(10,6),theMap);
	theMap->addEvent(&mainEvent);
	theMap->setMainEvent(&mainEvent);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(*theMap));
		window.display();
	}
}