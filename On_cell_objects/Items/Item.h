//
// Created by igor on 20.10.2021.
//
#ifndef OOPGAME_ITEM_H
#define OOPGAME_ITEM_H

#include "../../Type_item.h"

class Cell;
class Field;
class Player;

class Item {
public:
    virtual void pick_up_item(Player& player, Cell &cell) = 0;
    virtual Type_item get_item_type() = 0;

};

#endif //OOPGAME_ITEM_H
