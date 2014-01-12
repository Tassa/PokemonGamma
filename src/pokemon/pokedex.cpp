#ifndef POKEDEX_DATA_CPP
#define POKEDES_DATA_CPP

#include <string>
#include "attacks.h"

namespace Pokemon
{
	enum TypePokemon {Inconnu,Normal,Feu,Eau,Electrique,Plante,Glace,Combat,Poison,Sol,Vol,Psy,Insecte,Roche,Spectre,Dragon,Acier};

	class Pokemon_Data_Entry
	{
		std::string name;
		TypePokemon type1;
		TypePokemon type2;
		unsigned int capture_rate;
		
		unsigned int hp;
		unsigned int atk;
		unsigned int dfe;
		unsigned int spd;
		unsigned int ats;
		unsigned int dfs;

		Attaque *skills;

		unsigned int probability_female;
	};
}
#endif