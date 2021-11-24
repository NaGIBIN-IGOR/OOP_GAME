//
// Created by igor on 25.10.2021.
//

#pragma once



#include "Enemy.h"

class Tiny_enemy: public Enemy{
public:
    Tiny_enemy(unsigned x_coord, unsigned y_coord);
    friend std::ostream& operator<< (std::ostream &out, Tiny_enemy& enemy);

    unsigned get_health() override;
    unsigned get_damage() override;
    Type_enemy get_enemy_type() override;
    unsigned get_x_coordinate() override;
    unsigned get_y_coordinate() override;
    void set_health(unsigned int) override;
    void print(std::ostream& out) override;

private:
    unsigned health = 15;
    unsigned damage = 35;

};
 //OOP_GAME_TINY_ENEMY_H
