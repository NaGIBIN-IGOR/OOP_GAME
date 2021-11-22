//
// Created by igor on 24.10.2021.
//


#pragma once


#include <vector>
#include "Enemy.h"
#include "../../Diraction.h"

class Field;
class Enemy_controller{
public:
    Enemy_controller()= default;
    void make_action(std::vector<Enemy*>& enemies, Field &field);
//    void append_enemy(Enemy* enemy);
private:
    Diraction player_check(Field &field, unsigned x, unsigned y);
};
 //OOP_GAME_ENEMY_CONTROLLER_H
