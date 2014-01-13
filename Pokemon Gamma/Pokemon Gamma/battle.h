//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Yoshin 13/01/2014																//
//																																		//
//														Battle Core																		//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef BATTLE_H
#define BATTLE_H

enum CourbeXP { Rapide, Normale, Lente, Parabolique, Erratic, Fluctuante, TresRapide, TresLente };

int squared(int a);														//Return a*a

int cube(int a);														//Return a*a*a

unsigned int getNextExp(CourbeXP c, unsigned int level);				//Return the amount of experience need for next level

#endif