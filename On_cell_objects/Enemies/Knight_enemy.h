//
// Created by igor on 24.10.2021.
//

#ifndef OOP_GAME_KNIGHT_ENEMY_H
#define OOP_GAME_KNIGHT_ENEMY_H

#include "Enemy.h"
class Field;
class Cell;

class Knight_enemy : public Enemy{
public:
    Knight_enemy(unsigned x_coord, unsigned y_coord);
    friend std::ostream& operator<< (std::ostream &out, Knight_enemy& enemy);

    unsigned get_health() override;
    unsigned get_damage() override;
    Type_enemy get_enemy_type() override;
    unsigned get_x_coordinate() override;
    unsigned get_y_coordinate() override;
    void set_health(unsigned int) override;
    void print_enemy_inf(std::ostream& out) override;

private:
    unsigned health = 80;
    unsigned damage = 40;

};

#endif //OOP_GAME_KNIGHT_ENEMY_H
