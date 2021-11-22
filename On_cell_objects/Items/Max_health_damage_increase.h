//
// Created by igor on 20.10.2021.
//

#ifndef OOPGAME_HEAL_DAMAGE_ITEM_H
#define OOPGAME_HEAL_DAMAGE_ITEM_H
#include "Item.h"

class Max_health_damage_increase : public Item{
public:

    void pick_up_item(Player& player, Cell &cell) override;
    Type_item get_item_type() override;

private:
    unsigned health_increase_max = 10;
    unsigned damage_increase_max = 4;
};


#endif //OOPGAME_HEAL_DAMAGE_ITEM_H
