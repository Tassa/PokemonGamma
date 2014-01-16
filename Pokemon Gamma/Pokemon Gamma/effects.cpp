//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Garazbolg 10/01/2014															//
//																																		//
//														Effect_Core																		//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "effects.h"
#include "pokemon.h"

namespace Pokemon_data
{

		Effect_Change_Atk::Effect_Change_Atk(int argument) : arg(argument){}

		void Effect_Change_Atk::affect(Pokemon * p)
		{
			p->ChangeAtk(arg);
		}


		Effect_Change_Dfe::Effect_Change_Dfe(int argument) : arg(argument){}

		void Effect_Change_Dfe::affect(Pokemon * p)
		{
			p->ChangeDfe(arg);
		}


		Effect_Change_Spd::Effect_Change_Spd(int argument) : arg(argument){}

		void Effect_Change_Spd::affect(Pokemon * p)
		{
			p->ChangeSpd(arg);
		}


		Effect_Change_Ats::Effect_Change_Ats(int argument) : arg(argument){}

		void Effect_Change_Ats::affect(Pokemon * p)
		{
			p->ChangeAts(arg);
		}


		Effect_Change_Dfs::Effect_Change_Dfs(int argument) : arg(argument){}

		void Effect_Change_Dfs::affect(Pokemon * p)
		{
			p->ChangeDfs(arg);
		}


		Effect_Change_Esq::Effect_Change_Esq(int argument) : arg(argument){}

		void Effect_Change_Esq::affect(Pokemon * p)
		{
			p->ChangeEsq(arg);
		}


		Effect_Change_Prec::Effect_Change_Prec(int argument) : arg(argument){}

		void Effect_Change_Prec::affect(Pokemon * p)
		{
			p->ChangePrec(arg);
		}



		Effect_Change_Statut::Effect_Change_Statut(int argument) : arg(argument){}

		void Effect_Change_Statut::affect(Pokemon * p)
		{
			p->ChangeStatut(arg);
		}



		Effect_Heal::Effect_Heal(float argument) : arg(argument){}

		void Effect_Heal::affect(Pokemon * p)
		{
			p->Heal(arg);
		}

		Effect_Clonage::Effect_Clonage(){}

		void Effect_Clonage::affect(Pokemon * p)
		{
			p->SetClone();
		}


}