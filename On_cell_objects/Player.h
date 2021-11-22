//
// Created by igor on 19.10.2021.
//
#ifndef OOPGAME_PLAYER_H
#define OOPGAME_PLAYER_H

#include "fstream"
#include "./../Diraction.h"
#include "Subscriber.h"

class Field;
class Enemy;

class Player: public Subscriber{
public:
    Player()= default;

    friend std::ostream& operator<< (std::ostream &out, const Player& player);

    unsigned get_max_health() const;

    void set_max_health(unsigned);

    unsigned get_max_damage() const;

    void set_max_damage(unsigned);

    unsigned get_x_coordinate() const;

    unsigned get_y_coordinate() const;

    unsigned get_x_coordinate() override;

    unsigned get_y_coordinate() override;

    void set_x_coordinate(unsigned);

    void set_y_coordinate(unsigned);

    unsigned get_health() const;

    unsigned get_damage() const;

    unsigned get_health() override;

    unsigned get_damage() override;

    void set_health(unsigned);

    void set_damage(unsigned);

    void make_hit(Enemy& enemy);

    void move_left(Field &field);

    void move_right(Field &field);

    void move_up(Field &field);

    void move_down(Field &field);

    void make_move(Field& field, char wasdg);

    void print(std::ostream &out) override;
protected:

private:
    unsigned health = 100;
    unsigned max_health = 100;
    unsigned damage = 10;
    unsigned max_damage = 14;
    unsigned x_player_coordinate = -1;
    unsigned y_player_coordinate = -1;

};

#endif //OOPGAME_PLAYER_H
