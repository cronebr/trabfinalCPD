#include "type_class.h"

TypeClass TypeClass::getType()
{
    TypeClass type;
    type.id = this->id;
    type.damage_against_bug = this->damage_against_bug;
    type.damage_against_dark = this->damage_against_dark;
    type.damage_against_dragon = this->damage_against_dragon;
    type.damage_against_electric = this->damage_against_electric;
    type.damage_against_fairy = this->damage_against_fairy;
    type.damage_against_fight = this->damage_against_fight;
    type.damage_against_fire = this->damage_against_fire;
    type.damage_against_flying = this->damage_against_flying;
    type.damage_against_ghost = this->damage_against_ghost;
    type.damage_against_grass = this->damage_against_grass;
    type.damage_against_ground = this->damage_against_ground;
    type.damage_against_ice = this->damage_against_ice;
    type.damage_against_normal = this->damage_against_normal;
    type.damage_against_poison = this->damage_against_poison;
    type.damage_against_psychic = this->damage_against_psychic;
    type.damage_against_rock = this->damage_against_rock;
    type.damage_against_steel = this->damage_against_steel;
    type.damage_against_water = this->damage_against_water;
    return type;
}
void TypeClass::setType(TypeClass type)
{
    this->id = type.id;
    this->damage_against_bug = type.damage_against_bug;
    this->damage_against_dark = type.damage_against_dark;
    this->damage_against_dragon = type.damage_against_dragon;
    this->damage_against_electric = type.damage_against_electric;
    this->damage_against_fairy = type.damage_against_fairy;
    this->damage_against_fight = type.damage_against_fight;
    this->damage_against_fire = type.damage_against_fire;
    this->damage_against_flying = type.damage_against_flying;
    this->damage_against_ghost = type.damage_against_ghost;
    this->damage_against_grass = type.damage_against_grass;
    this->damage_against_ground = type.damage_against_ground;
    this->damage_against_ice = type.damage_against_ice;
    this->damage_against_normal = type.damage_against_normal;
    this->damage_against_poison = type.damage_against_poison;
    this->damage_against_psychic = type.damage_against_psychic;
    this->damage_against_rock = type.damage_against_rock;
    this->damage_against_steel = type.damage_against_steel;
    this->damage_against_water = type.damage_against_water;
}
