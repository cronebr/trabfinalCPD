#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TypeClass
{
private:
    int id;
    string name;
    float damage_against_bug;
	float damage_against_dark;
	float damage_against_dragon;
	float damage_against_electric;
	float damage_against_fairy;
	float damage_against_fight;
	float damage_against_fire;
	float damage_against_flying;
	float damage_against_ghost;
	float damage_against_grass;
	float damage_against_ground;
	float damage_against_ice;
	float damage_against_normal;
	float damage_against_poison;
	float damage_against_psychic;
	float damage_against_rock;
	float damage_against_steel;
	float damage_against_water;

public:
    TypeClass getType();
    void setType(TypeClass type);
};
