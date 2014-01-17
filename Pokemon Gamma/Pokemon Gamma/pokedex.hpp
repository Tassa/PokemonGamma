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
#include <map>
#include "attacks.h"

#define NB_MAX_POKEMON 493

namespace Pokemon_data
{
	enum TypePokemon { Inconnu, Normal, Feu, Eau, Electrique, Plante, Glace, Combat, Poison, Sol, Vol, Psy, Insecte, Roche, Spectre, Dragon, Acier };

	enum NaturePokemon {};

	class Pokemon_Data_Entry
	{

	public :
		std::string name;														//Nom de l'espèce
		TypePokemon type1;														//Type primaire de l'espèce
		TypePokemon type2;														//Type secondaire de l'espèce


		unsigned int hp;														//Stats de base du Pokemon
		unsigned int atk;
		unsigned int dfe;
		unsigned int spd;
		unsigned int ats;
		unsigned int dfs;

		std::map< unsigned int, unsigned int > skills_table;							//Attaques que le pokemon va apprendre 
		std::map< unsigned int, unsigned int > skills_allows;						//Attaques que le pokemon peut apprendre (CT,CS)

		unsigned int probability_female;										//Probabilité que ce pokemon soit une femelle
		unsigned int capture_rate;												//Probabilité de capturer ce pokemon avec une pokeball
	};

	Pokemon_Data_Entry Pokedex_data[NB_MAX_POKEMON];

}
#endif