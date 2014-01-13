//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Garazbolg 10/01/2014															//
//																																		//
//														Experience_Table																//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef EXP_H
#define EXP_H

enum CourbeXP { Rapide, Normale, Lente, Parabolique, Erratic, Fluctuante, TresRapide, TresLente };

int squared(int a);														//Return a*a
int cube(int a);														//Return a*a*a

unsigned int getNextExp(CourbeXP c, unsigned int level);				//Return the amount of experience need for next level

#endif