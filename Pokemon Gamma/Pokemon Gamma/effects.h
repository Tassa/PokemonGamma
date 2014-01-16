//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Garazbolg 10/01/2014															//
//																																		//
//														Effect_Core.h																	//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "pokemon.h"

namespace Pokemon_data
{

	class Effect
	{
		virtual void affect(Pokemon * p) = 0;
	};

	class Effect_On_Time
	{
		virtual void affect(Pokemon * p) = 0;
	};



	class Effect_Change_Atk : Effect
	{
		Effect_Change_Atk(int argument);

		void affect(Pokemon * p);

	protected :
		int arg;

	};

	class Effect_Change_Dfe : Effect
	{
		Effect_Change_Dfe(int argument);

		void affect(Pokemon * p);

	protected:
		int arg;

	};

	class Effect_Change_Spd : Effect
	{
		Effect_Change_Spd(int argument);

		void affect(Pokemon * p);

	protected:
		int arg;

	};

	class Effect_Change_Ats : Effect
	{
		Effect_Change_Ats(int argument);

		void affect(Pokemon * p);

	protected:
		int arg;

	};

	class Effect_Change_Dfs : Effect
	{
		Effect_Change_Dfs(int argument);

		void affect(Pokemon * p);

	protected:
		int arg;

	};

	class Effect_Change_Esq : Effect
	{
		Effect_Change_Esq(int argument);

		void affect(Pokemon * p);

	protected:
		int arg;

	};

	class Effect_Change_Prec : Effect
	{
		Effect_Change_Prec(int argument);

		void affect(Pokemon * p);

	protected:
		int arg;

	};



	class Effect_Change_Statut : Effect
	{
		Effect_Change_Statut(int argument);

		void affect(Pokemon * p);

	protected:
		int arg;

	};

	class Effect_Heal : Effect
	{
		Effect_Heal(float argument);

		void affect(Pokemon * p);

	protected:
		float arg;

	};

	class Effect_Clonage : Effect
	{
		Effect_Clonage();

		void affect(Pokemon * p);
	};

}