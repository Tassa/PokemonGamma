//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Garazbolg 18/01/2013															//
//																																		//
//														Direction																		//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "direction.h"
namespace MapEngine
{

	Direction directionOpposee(const Direction & d)
	{
		switch (d)
		{
		case Gauche:
			return Droite;
			break;
		case Droite:
			return Gauche;
			break;
		case Haut:
			return Bas;
			break;
		case Bas:
			return Haut;
			break;
		default:
			return Aucune;
			break;
		}
	}
}