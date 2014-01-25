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
#include "attacks.h"
#include "pokedex.hpp"
#include "effects.h"

namespace Pokemon_data
{
	Attaque::Attaque()
	{
		name = "";
		type = Normal;
		power = 0;
		precision = 100;
		categorie = Physique;
		basePpMax = 0;
		cible = true;
		contact = true;
		priorite = 5;
		description = "";
		effet = NULL;
		probabilityEffet = 0.f;
		critElevee = false;
	}

}