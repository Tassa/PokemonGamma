//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Yoshin 13/01/2014																//
//																																		//
//														Attacks																			//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef ATTACKS_H
#define ATTACKS_H

#include <string>
#include "pokemon.h"
#include "effects.h"
#include "pokedex.hpp"
#include "attacks.h"

#define NB_MAX_SKILLS 200

namespace Pokemon_data
{

	enum CategorieAttaque { Physique, Speciale, Statut };

	class Attaque
	{
		std::string name;
		TypePokemon type;								//Type de l'attaque
		unsigned int power;								//Puissance
		unsigned int precision;							//Precision
		CategorieAttaque categorie; 					//Physique , Spéciale , Statut
		unsigned int ppMax;
		unsigned int ppCurent;
		bool cible;										//True => Ally, False => Enemy
		bool contact;
		unsigned int priorite;
		std::string description;
		Effect* effet;
		float probabilityEffet;
		bool critElevee;

	};

	Attaque skills_data[NB_MAX_SKILLS];


}

#endif