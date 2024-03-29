//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Garazbolg 18/01/2013															//
//																																		//
//														Direction.h																		//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef DIRECTION_H
#define DIRECTION_H

#include <utility>
namespace MapEngine
{

#define MIN_VAL_FOR_VECTORS_2D 0.2

	enum Direction {
		Bas,
		Gauche,
		Droite,
		Haut,
		Gauche_Bas,
		Gauche_Haut,
		Droite_Bas,
		Droite_Haut,
		Aucune
	};

	Direction directionOpposee(const Direction & d);

}
#endif //DIRECTION_H
