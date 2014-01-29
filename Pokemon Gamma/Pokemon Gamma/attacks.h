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
#include "pokedex.hpp"



#define NB_MAX_SKILLS 200

namespace Pokemon_data
{

	class Effect;

	enum CategorieAttaque { Physique, Speciale, Statut };

	class Attaque
	{
	public :
		Attaque();
	protected :
		std::string name;
		TypePokemon type;								//Type de l'attaque
		unsigned int power;								//Puissance
		unsigned int precision;							//Precision
		CategorieAttaque categorie; 					//Physique , Spéciale , Statut
		unsigned short basePpMax;

		bool cible;										//True => Ally, False => Enemy
		bool contact;
		unsigned int priorite;
		std::string description;
		Effect * effet;
		float probabilityEffet;
		bool critElevee;

	};

	extern Attaque skills_data[NB_MAX_SKILLS];


}

#endif