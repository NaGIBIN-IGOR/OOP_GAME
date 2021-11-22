//
// Created by igor on 20.10.2021.
//

#pragma once



#include "Item.h"

class Damage_increase_item : public Item{
public:

    void pick_up_item(Player& player, Cell &cell) override;
    Type_item get_item_type() override;

private:
    unsigned health_decrease = 10;
    unsigned damage_increase = 4;
};

 //OOPGAME_DAMAGE_ITEM_H
