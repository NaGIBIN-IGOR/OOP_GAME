//
// Created by igor on 25.10.2021.
//

#include <iostream>
#include "Ogre_enemy.h"
#define OGRE_MAX_HP 150

Ogre_enemy::Ogre_enemy(unsigned int x_coord, unsigned int y_coord) {
    x = x_coord;
    y = y_coord;
}

unsigned Ogre_enemy::get_health() {
    return health;
}

unsigned Ogre_enemy::get_damage() {
    return damage;
}

Type_enemy Ogre_enemy::get_enemy_type() {
    return OGRE;
}

unsigned Ogre_enemy::get_x_coordinate() {
    return x;
}

unsigned Ogre_enemy::get_y_coordinate() {
    return y;
}

void Ogre_enemy::set_health(unsigned int new_helth) {
    if(new_helth > OGRE_MAX_HP) health = OGRE_MAX_HP;
    else health = new_helth;
}

void Ogre_enemy::print_enemy_inf(std::ostream &out) {
//    out << "Огр имеет: " << this->get_health() << " здоровья  и " << this->get_damage() << " урона";
    out << *this;
}

std::ostream &operator<<(std::ostream &out,  Ogre_enemy &enemy) {
//    out << "Огр имеет: " << enemy.get_health() << " здоровья  и " << enemy.get_damage() << " урона";
    out << "Огр:";
    return out;
}
