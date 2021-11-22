//
// Created by igor on 20.10.2021.
//
#include "Damage_increase_item.h"
#include "../../Cell/Cell.h"
#include "../../Field/Field.h"
#include "../Player.h"



void Damage_increase_item::pick_up_item(Player &player, Cell &cell) {
    player.set_damage(player.get_damage() + damage_increase);
    if (player.get_damage() > player.get_max_damage()) {
        player.set_damage(player.get_max_damage());
    }
    if ((int) player.get_health() - (int) health_decrease <= 0) {
        player.set_health(0);
    }
    else {
        player.set_health(player.get_health() - health_decrease);
    }
    cell.remove_item();
}

Type_item Damage_increase_item::get_item_type() {
    return DAMAGE_INCREASE;
}