//
// Created by igor on 20.10.2021.
//

#ifndef OOPGAME_HEAL_ITEM_H
#define OOPGAME_HEAL_ITEM_H

#include "Item.h"

class Heal_item : public Item{
public:
    void pick_up_item(Player& player, Cell &cell) override;
    Type_item get_item_type() override;

private:
    unsigned heal = 20;
    unsigned damage_decrease = 2;
};
#endif //OOPGAME_HEAL_ITEM_H
