//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Yoshin 13/01/2014																//
//																																		//
//														Battle_Core																		//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace BattleCore
{

	class Battle
	{

	public:
		Battle::Battle(Dresseur & myDresseur, const unsigned int & idNpc)
		{
			dresseur = myDresseur;
			npc = idNpc;

			id = 0;
		}

		void Battle::newBattle()
		{
			id = getId();
		}

		unsigned int getId()
		{

		}

	protected:
		unsigned int id;				// ID du Combat
		Dresseur dresseur;	         	// Dresseur
		unsigned int npc;				// ID du npc

	};

}