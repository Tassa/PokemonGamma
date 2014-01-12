//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Garazbolg 10/01/2014															//
//																																		//
//														Effect_Core																		//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "pokemon.h"

namespace Pokemon
{

	class Effect
	{
		virtual void Effect::affect(Pokemon * p) = 0;
	};

	class Effect_On_Time
	{
		virtual void Effect_On_Time::affect(Pokemon * p) = 0;
	};



	class Effect_Change_Atk : Effect
	{
		Effect_Change_Atk::Effect_Change_Atk(int argument) : arg(argument){}

		int arg;
	
		void Effect_Change_Atk::affect(Pokemon * p)
		{
			p->ChangeAtk(arg);
		}
	};

	class Effect_Change_Dfe : Effect
	{
		Effect_Change_Dfe::Effect_Change_Dfe(int argument) : arg(argument){}

		int arg;
	
		void Effect_Change_Dfe::affect(Pokemon * p)
		{
			p->ChangeDfe(arg);
		}
	};

	class Effect_Change_Spd : Effect
	{
		Effect_Change_Spd::Effect_Change_Spd(int argument) : arg(argument){}

		int arg;
	
		void Effect_Change_Spd::affect(Pokemon * p)
		{
			p->ChangeSpd(arg);
		}
	};

	class Effect_Change_Ats : Effect
	{
		Effect_Change_Ats::Effect_Change_Ats(int argument) : arg(argument){}

		int arg;
	
		void Effect_Change_Ats::affect(Pokemon * p)
		{
			p->ChangeAts(arg);
		}
	};

	class Effect_Change_Dfs : Effect
	{
		Effect_Change_Dfs::Effect_Change_Dfs(int argument) : arg(argument){}

		int arg;
	
		void Effect_Change_Dfs::affect(Pokemon * p)
		{
			p->ChangeDfs(arg);
		}
	};

	class Effect_Change_Esq : Effect
	{
		Effect_Change_Esq::Effect_Change_Esq(int argument) : arg(argument){}

		int arg;
	
		void Effect_Change_Esq::affect(Pokemon * p)
		{
			p->ChangeEsq(arg);
		}
	};

	class Effect_Change_Prec : Effect
	{
		Effect_Change_Prec::Effect_Change_Prec(int argument) : arg(argument){}

		int arg;
	
		void affect(Pokemon * p)
		{
			p->ChangePrec(arg);
		}
	};



	class Effect_Change_Statut : Effect
	{
		Effect_Change_Statut::Effect_Change_Statut(int argument) : arg(argument){}

		int arg;
	
		void Effect_Change_Statut::affect(Pokemon * p)
		{
			p->ChangeStatut(arg);
		}
	};

	class Effect_Heal : Effect
	{
		Effect_Heal::Effect_Heal(float argument) : arg(argument){}

		float arg;
	
		void Effect_Heal::affect(Pokemon * p)
		{
			p->Heal(arg);
		}
	};

	class Effect_Clonage : Effect
	{
		Effect_Clonage::Effect_Clonage(){}
	
		void Effect_Clonage::affect(Pokemon * p)
		{
			p->SetClone();
		}
	};

}