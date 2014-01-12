//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Garazbolg 10/01/2014															//
//																																		//
//														Attaque_Core																	//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <string>
#include "pokemon.h"


namespace Pokemon
{

	enum CategorieAttaque {Physique , Speciale , Statut};

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
		Effect effet;
		float probabilityEffet;
		bool critElevee;
	}

}