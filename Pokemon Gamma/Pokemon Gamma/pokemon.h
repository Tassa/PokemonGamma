//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Yoshin 13/01/2014																//
//																																		//
//														Pokemon																			//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef POKEMON_H
#define POKEMON_H

enum CourbeXP { Rapide, Normale, Lente, Parabolique, Erratic, Fluctuante, TresRapide, TresLente };

#define SQUARED(x) ((x) * (x))											//Return a*a
#define CUBE(x) ((x) * (x) * (x))											//Return a*a*a

unsigned int getNextExp(CourbeXP c, unsigned int level);				//Return the amount of experience need for next level

#endif