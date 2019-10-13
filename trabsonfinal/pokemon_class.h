#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Definição da classe pokémon.
class PokemonClass
{
private:
	vector<string> abilities;
	float multiplier_against_bug;
	float multiplier_against_dark;
	float multiplier_against_dragon;
	float multiplier_against_electric;
	float multiplier_against_fairy;
	float multiplier_against_fight;
	float multiplier_against_fire;
	float multiplier_against_flying;
	float multiplier_against_ghost;
	float multiplier_against_grass;
	float multiplier_against_ground;
	float multiplier_against_ice;
	float multiplier_against_normal;
	float multiplier_against_poison;
	float multiplier_against_psychic;
	float multiplier_against_rock;
	float multiplier_against_steel;
	float multiplier_against_water;
	int attack;
	int base_egg_steps;
	int base_happiness;
	int base_total;
	float capture_rate;
	string classfication;
	int defense;
	long int experience_growth;
	float height_m;
	int hp;
	string japanese_name;
	string name;
	float percentage_male;
	int pokedex_number;
	int sp_attack;
	int sp_defense;
	int speed;
	string type1;
	string type2;
	float weight_kg;
	int generation;
	bool is_legendary;
	//funções para setar o objeto pokemon
public:
	string getPokemon();		//extrai a string do csv
	PokemonClass validateString(string pokemonToInsert);//transforma a string em um objeto
	void setPokemon(PokemonClass pokemon);	//seta o objeto da função main com o objeto que a validate string criou

	string getname()
	{
		return this->name;
	}

	void insertnome(string name)
	{
		this->name = name;
	}
};
