//
// Created by igor on 20.10.2021.
//

#include "Max_health_damage_increase.h"
#include "../../Cell/Cell.h"
#include "../../Field/Field.h"
#include "../Player.h"


void Max_health_damage_increase::pick_up_item(Player &player, Cell &cell) {
        player.set_max_damage(player.get_max_damage() + damage_increase_max);
        player.set_max_health(player.get_max_health() + health_increase_max);
        player.set_health(player.get_max_health());
        player.set_damage(player.get_max_damage());
        cell.remove_item();
}

Type_item Max_health_damage_increase::get_item_type() {
    return MAX_HEAL_DAMAGE_INCREASE;
}