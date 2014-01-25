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

#include <string>
#include "exp.h"
#include "attacks.h"
#include "pokedex.hpp"

namespace Pokemon_data
{
	enum GenrePokemon { Aucun, Male, Femelle };

	class Pokemon
	{

	public:


		Pokemon(const unsigned int & idIN,
			const bool & shineyIN, const unsigned int & levelIN,
			const NaturePokemon & natureIN,
			const unsigned int & capSpeIn,
			const GenrePokemon & genderIN,
			const std::string & nameIN,
			const unsigned int & item,
			const unsigned int & happynessIN,
			const unsigned int & iv_hp,
			const unsigned int & iv_atk,
			const unsigned int & iv_dfe,
			const unsigned int & iv_spd,
			const unsigned int & iv_ats,
			const unsigned int & iv_dfs,
			const unsigned int & skill1,
			const unsigned int & skill2,
			const unsigned int & skill3,
			const unsigned int & skill4,
			const unsigned int & formeIN);


		void ChangeAtk(const int & arg);

		void ChangeDfe(const int & arg);

		void ChangeSpd(const int & arg);

		void ChangeAts(const int & arg);

		void ChangeDfs(const int & arg);

		void ChangeEsq(const int & arg);

		void ChangePrec(const int & arg);


		void ChangeStatut(const int & arg);

		void Heal(const float & arg);

		void SetClone();

	protected:
		unsigned int id;				// ID du Pokémon
		std::string name;					// Nom générique de l'espèce
		NaturePokemon nature;         	// Code "caractère" du Pokémon
		bool shiny;          			// Caractère Shiny
		GenrePokemon gender;         	// 0 sans genre 1 male 2 femelle
		std::string given_name;   			// Nom donné au Pokémon
		unsigned int level;

		unsigned int hp;        		// Stats
		unsigned int atk;
		unsigned int dfe;
		unsigned int spd;
		unsigned int ats;
		unsigned int dfs;

		unsigned int dv_hp;        		// Stats Innee
		unsigned int dv_atk;
		unsigned int dv_dfe;
		unsigned int dv_spd;
		unsigned int dv_ats;
		unsigned int dv_dfs;

		Attaque* skills[4];
		TypePokemon type1;
		TypePokemon type2;

		unsigned int ability;      	// Capacité propre du Pokémon
		unsigned int capture_rate;       	// Taux de Capture
		

		// Statut_Variable
		unsigned int status;
		unsigned int status_count;

		unsigned int item_hold;      	// ID objet tenu
		unsigned int happyness;

		// Stats de combat
		int hp_stage;
		int atk_stage;
		int dfe_stage;
		int spd_stage;
		int ats_stage;
		int dfs_stage;
		int eva_stage;
		int acc_stage;

		unsigned int forme;                // Le numéro de la forme alt
		unsigned int clone_pv;
	};

	class Pokemon_owned : Pokemon
	{

		bool add_exp(int arg);

		bool upgrade_level();

		bool learnMove(unsigned int moveToLearn);

	protected:

		CourbeXP exp_type;      				// Expérience: Courbe d'éxpérience

		// Caractéristiques
		unsigned int code;          			// Code indentification propre au Pokémon
		unsigned int trainer_id;
		std::string trainer_name;

		unsigned int exp;						//Experience actuel
		unsigned int expNext;					//Expérience avant le niveau suivant

		unsigned int atk_plus;     				// Effort Value (EV)
		unsigned int dfe_plus;
		unsigned int spd_plus;
		unsigned int ats_plus;
		unsigned int dfs_plus;
		unsigned int hp_plus;

		unsigned short ppCurrent[4];
		unsigned short ppMax[4];


		// Stat concours
		unsigned int sang_froid;
		unsigned int robustesse;
		unsigned int beaute;
		unsigned int intelligence;
		unsigned int grace;

		unsigned int ball_data;           		// Sprite de la ball utilisée
		unsigned int obeissance;
	};

	class Pokemon_Egg : Pokemon_owned
	{

	protected :
		unsigned int step_remaining;      		// pas restants avant éclosion

	};
}




#endif