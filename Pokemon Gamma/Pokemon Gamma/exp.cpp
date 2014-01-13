//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Garazbolg 10/01/2014															//
//																																		//
//														Experience_Table																//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "exp.h"
#include <cmath> 

int squared(int a)
{
	return a*a;
}

int cube(int a)
{
	return a*a*a;
}

unsigned int getNextExp(CourbeXP c, unsigned int level)
{
	switch (c)
	{
	case Rapide:
		return (unsigned int)(0.85*(cube(level)));
		break;

	case Normale:
		return (unsigned int)(cube(level));
		break;

	case Lente:
		return (unsigned int)(1.2*(cube(level)));
			break;

	case Parabolique:
		return (unsigned int)((1.2*(cube(level)) - 15 * (squared(level)) + 100 * level - 85));
			break;

	case Erratic:
		if (level <= 50)
			return (unsigned int)((cube(level))*(120 - level) / 70.0);

		if (level > 50 && level <= 75)
			return (unsigned int)((cube(level))*(200 - level) / 150.0 + ((level - 50)*level * 10));

		if (level > 75 && level <= 99)
		{
			switch (level % 3)
			{
			case 0:
				return (unsigned int)(((cube(level)) * (1.08111 - (level / 368.85) - 0)));
					break;


			case 1:
				return (unsigned int)(((cube(level)) * (1.08111 - (level / 368.85) - 0.010)));
					break;

			case 2:
				return (unsigned int)(((cube(level)) * (1.08111 - (level / 368.85) - 0.016)));
					break;
			}
		}

		if (level >= 100)
			return (unsigned int)((cube(level)) * (0.8 - ((level - 100) / 3100)) + cos(level - 100) * 20000);

		break;

	case Fluctuante:
		if (level <= 15)
			return (unsigned int)((cube(level))* (24 + (level + 1) / 3) / 50);

		if (level > 15 && level <= 35)
			return (unsigned int)((cube(level))* (14 + level) / 50);

		if (level > 35 && level <= 55)
			return (unsigned int)((cube(level)) * (32 + (level / 2)) / 50);

		if (level > 55)
			return (unsigned int)((cube(level)) * (62.2 + (level / 20)) / 50);

		break;

	case TresRapide:
		return (unsigned int)(0.75*(cube(level)));
			break;

	case TresLente:
		return (unsigned int)(1.35*(cube(level)));
			break;
	}
} 