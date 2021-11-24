//
// Created by igor on 24.10.2021.
//

#pragma once



#include <string>
#include "./../../Type_enemy.h"
#include "./../../Diraction.h"
#include "../Subscriber.h"

class Field;
class Player;

class Enemy: public Subscriber{
public:
//    friend std::ostream& operator<< (std::ostream &out, Enemy& enemy);

    virtual unsigned get_health() = 0;
    virtual unsigned get_damage() = 0;
    virtual unsigned get_x_coordinate() = 0;
    virtual unsigned get_y_coordinate() = 0;
    virtual Type_enemy get_enemy_type() = 0;
    virtual void print(std::ostream& out) = 0;

    void make_move(Field& field, Diraction);

    void make_hit(Player& player);

    void take_hit(unsigned dmg);
private:

    void move_left(Field &field);

    void move_right(Field &field);

    void move_up(Field &field);

    void move_down(Field &field);

protected:
//    void print(std::ostream &out) override;
    virtual void set_health(unsigned ) = 0;

    unsigned x, y;
};

 //OOP_GAME_ENEMY_H
