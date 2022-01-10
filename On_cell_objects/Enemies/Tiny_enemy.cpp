//
// Created by igor on 25.10.2021.
//
#define TINY_MAX_HP 15


#include "Tiny_enemy.h"
#include <iostream>

Tiny_enemy::Tiny_enemy(unsigned int x_coord, unsigned int y_coord) {
    x = x_coord;
    y = y_coord;
}
unsigned Tiny_enemy::get_health() {
    return health;
}
unsigned Tiny_enemy::get_damage() {
    return damage;
}
Type_enemy Tiny_enemy::get_enemy_type() {
    return TINY;
}

unsigned Tiny_enemy::get_x_coordinate() {
    return x;
}

unsigned Tiny_enemy::get_y_coordinate() {
    return y;
}

void Tiny_enemy::set_health(unsigned new_health) {
    if(new_health > TINY_MAX_HP) health = TINY_MAX_HP;
    else health = new_health;
}

void Tiny_enemy::print(std::ostream &out) {
    out<<*this;
}
std::ostream &operator<<(std::ostream &out,  Tiny_enemy &enemy) {
    out << "Тини";
    return out;
}

Tiny_enemy::Tiny_enemy(unsigned int x_coord, unsigned int y_coord, unsigned int health, unsigned int damage) :
        health(health),damage(damage){
    x = x_coord;
    y = y_coord;

}
