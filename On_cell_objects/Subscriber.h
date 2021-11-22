//
// Created by igor on 16.11.2021.
//

#ifndef OOP_GAME_SUBSCRIBER_H
#define OOP_GAME_SUBSCRIBER_H
#include "iostream"

class Subscriber{
public:
    virtual unsigned get_health() = 0;
    virtual unsigned get_damage() = 0;
    virtual unsigned get_x_coordinate() = 0;
    virtual unsigned get_y_coordinate() = 0;
    virtual void print(std::ostream &out) = 0;

    friend std::ostream& operator<< (std::ostream &out,  Subscriber& sub);
protected:
};


#endif //OOP_GAME_SUBSCRIBER_H
