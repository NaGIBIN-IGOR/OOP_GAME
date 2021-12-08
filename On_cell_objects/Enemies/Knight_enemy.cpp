//
// Created by igor on 24.10.2021.
//

#define KNIGHT_MAX_HP 20

#include <iostream>
#include "Knight_enemy.h"
#include "../../Cell/Cell.h"

unsigned Knight_enemy::get_health() {
    return health;
}
unsigned Knight_enemy::get_damage() {
    return damage;
}
Type_enemy Knight_enemy::get_enemy_type() {
    return KNIGHT;
}

unsigned Knight_enemy::get_x_coordinate() {
    return x;
}

unsigned Knight_enemy::get_y_coordinate() {
    return y;
}

void Knight_enemy::set_health(unsigned new_health) {
    if(new_health > KNIGHT_MAX_HP) health = KNIGHT_MAX_HP;
    else health = new_health;
}

Knight_enemy::Knight_enemy(unsigned x_coord, unsigned y_coord){
    x = x_coord;
    y = y_coord;
}

void Knight_enemy::print(std::ostream &out) {
//    out << "Рыцарь имеет: " << this->get_health() << " здоровья  и " << this->get_damage() << " урона";
    out << *this;
}

std::ostream &operator<<(std::ostream &out,  Knight_enemy &enemy) {
//    out << "Рыцарь имеет: " << enemy.get_health() << " здоровья  и " << enemy.get_damage() << " урона";
    out << "Рыцарь";
    return out;
}