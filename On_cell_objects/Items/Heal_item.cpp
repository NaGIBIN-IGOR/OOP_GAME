//
// Created by igor on 20.10.2021.
//

#include "Heal_item.h"
#include "../../Cell/Cell.h"
#include "../../Field/Field.h"
#include "../Player.h"

void Heal_item::pick_up_item(Player &player, Cell &cell) {
    player.set_health(player.get_health() + heal);
    if (player.get_health() > player.get_max_health()) {
        player.set_health(player.get_max_health());
    }
    if ((int)player.get_damage() - (int)damage_decrease <= 0) {
        player.set_damage(0);
    }
    else{
        player.set_damage(player.get_damage() - damage_decrease);
    }
    cell.remove_item();
}

Type_item Heal_item::get_item_type() {
    return HEAL;
}