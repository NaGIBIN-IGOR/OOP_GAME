//
// Created by igor on 25.10.2021.
//

#ifndef OOP_GAME_OGRE_ENEMY_H
#define OOP_GAME_OGRE_ENEMY_H

#include "Enemy.h"

class Ogre_enemy : public Enemy{
public:

    Ogre_enemy(unsigned x_coord, unsigned y_coord);
    friend std::ostream& operator<< (std::ostream &out, Ogre_enemy& enemy);

    unsigned get_health() override;
    unsigned get_damage() override;
    Type_enemy get_enemy_type() override;
    unsigned get_x_coordinate() override;
    unsigned get_y_coordinate() override;
    void set_health(unsigned int) override;
    void print_enemy_inf(std::ostream& out) override;

private:
    unsigned health = 150;
    unsigned damage = 60;

};

#endif //OOP_GAME_OGRE_ENEMY_H
