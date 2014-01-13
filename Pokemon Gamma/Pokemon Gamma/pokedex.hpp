//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Garazbolg 10/01/2014															//
//																																		//
//														Pokedex																			//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef POKEDEX_DATA_CPP
#define POKEDEX_DATA_CPP

#include <string>
//#include "attacks.h"

namespace Pokemon
{
	enum TypePokemon { Inconnu, Normal, Feu, Eau, Electrique, Plante, Glace, Combat, Poison, Sol, Vol, Psy, Insecte, Roche, Spectre, Dragon, Acier };

	class Pokemon_Data_Entry
	{
		std::string name;														//Nom de l'esp�ce
		TypePokemon type1;														//Type primaire de l'esp�ce
		TypePokemon type2;														//Type secondaire de l'esp�ce


		unsigned int hp;														//Stats de base du Pokemon
		unsigned int atk;
		unsigned int dfe;
		unsigned int spd;
		unsigned int ats;
		unsigned int dfs;

		std::map<unsigned int, Attaque*> skills_table;							//Attaques que le pokemon va apprendre 
		std::map<unsigned int, Attaque*> skills_allows;							//Attaques que le pokemon peut apprendre (CT,CS)

		unsigned int probability_female;										//Probabilit� que ce pokemon soit une femelle
		unsigned int capture_rate;												//Probabilit� de capturer ce pokemon avec une pokeball
	};
}
#endif