//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//																																		//
//														Pokemon Gamma Engine															//
//														Garazbolg 10/01/2014															//
//																																		//
//														Pokemon_Core																	//
//																																		//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <string>
#include "exp.h"
#include "attacks.h"
#include "pokedex.h"

namespace Pokemon
{
	enum GenrePokemon {Aucun,Male,Femelle};

	class Pokemon
	{
	
	public:
	
	
		Pokemon::Pokemon(	const unsigned int & idIN,
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
							const unsigned int & formeIN)
		{
			id = idIN;
			level = levelIN;
			gender = genderIN;
			given_name = nameIN;
			shiny = shineyIN;
			nature = natureIN;
			ability = capSpeIn;
			item_hold = item;
			happyness = happynessIN;
			
			dv_hp = iv_hp;
			dv_atk = iv_atk;
			dv_dfe = iv_dfe;
			dv_spd = iv_spd;
			dv_ats = iv_ats;
			dv_dfs = iv_dfs;
			
			skills[0] = skill1;
			skills[1] = skill2;
			skills[2] = skill3;
			skills[3] = skill4;
			
			forme = formeIN;
			
			
			
			name = Pokedex_data[id].name;
			type1 = Pokedex_data[id].type1;
			type2 = Pokedex_data[id].type2;
			capture_rate = Pokedex_data[id].capture_rate;
			
			status = 0;
			status_count = 0;
			clone_pv = 0;
		
			
			// Stats
			hp = (unsigned int)((2.0 * Pokedex_data[id].hp * dv_hp) * (level/100.0) + level*10);
			atk = (unsigned int)((2.0 * Pokedex_data[id].atk * dv_atk) * (level/100.0) + 5);
			dfe = (unsigned int)((2.0 * Pokedex_data[id].dfe * dv_dfe) * (level/100.0) + 5);
			spd = (unsigned int)((2.0 * Pokedex_data[id].spd * dv_spd) * (level/100.0) + 5);
			ats = (unsigned int)((2.0 * Pokedex_data[id].ats * dv_ats) * (level/100.0) + 5);
			dfs = (unsigned int)((2.0 * Pokedex_data[id].dfs * dv_dfs) * (level/100.0) + 5);
			eva_stage = 0;
			acc_stage = 0;
			
			hp_stage = hp;
			atk_stage = 0;
			dfe_stage = 0;
			spd_stage = 0;
			ats_stage = 0;
			dfs_stage = 0;
			
		}
	
		
		void Pokemon::ChangeAtk(const int & arg)
		{
			atk_stage += arg;
			if(atk_stage<(-6)){atk_stage = -6;}
			if(atk_stage>6){atk_stage = 6;}
		}
		
		void Pokemon::ChangeDfe(const int & arg)
		{
			dfe_stage += arg;
			if(dfe_stage<(-6)){dfe_stage = -6;}
			if(dfe_stage>6){dfe_stage = 6;}
		}
		
		void Pokemon::ChangeSpd(const int & arg)
		{
			spd_stage += arg;
			if(spd_stage<(-6)){spd_stage = -6;}
			if(spd_stage>6){spd_stage = 6;}
		}
		
		void Pokemon::ChangeAts(const int & arg)
		{
			ats_stage += arg;
			if(ats_stage<(-6)){ats_stage = -6;}
			if(ats_stage>6){ats_stage = 6;}
		}
		
		void Pokemon::ChangeDfs(const int & arg)
		{
			dfs_stage += arg;
			if(dfs_stage<(-6)){dfs_stage = -6;}
			if(dfs_stage>6){dfs_stage = 6;}
		}
		
		void Pokemon::ChangeEsq(const int & arg)
		{
			eva_stage += arg;
			if(eva_stage<(-6)){eva_stage = -6;}
			if(eva_stage>6){eva_stage = 6;}
		}
		
		void Pokemon::ChangePrec(const int & arg)
		{
			acc_stage += arg;
			if(acc_stage<(-6)){acc_stage = -6;}
			if(acc_stage>6){acc_stage = 6;}
		}
		
		
		void Pokemon::ChangeStatut(const int & arg)
		{
			if(!status){status = arg;}
		}
	
		void Pokemon::Heal(const float & arg)
		{
			hp_stage += (unsigned int) (hp*arg);
			if(hp_stage>hp){hp_stage = hp;}
		}
	
		void Pokemon::SetClone()
		{
			unsigned int tempHp = (unsigned int) (hp*0.25);
			if(hp_stage-tempHp > 0)
			{
				clone_pv = tempHp;
				hp_stage -= tempHp;
			}
			else
			{
				//write(/*Attaque Echoué*/);
			}
		}
		
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
		
		Attaque skills[4];
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
	
		int upgrade_level()
		{
			level += 1;
			exp = 0;
		}
	
	protected :
		
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
		
		unsigned int step_remaining;      		// pas restants avant éclosion
		
	}
}


