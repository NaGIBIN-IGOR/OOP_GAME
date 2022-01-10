//
// Created by igor on 23.12.2021.
//

#pragma once

#include "json.hpp"
#include "../Game/Game.h"
#include "../Field/Field.h"
#include "../Cell/Cell.h"
#include "../Enums/Type_cell.h"
#include "../Conditions/Win_condition_items.h"
#include "../Conditions/Win_condition_exit.h"
#include "../Enums/Type_enemy.h"
#include "../Enums/Type_item.h"
#include "../On_cell_objects/Items/Max_health_damage_increase.h"
#include "../On_cell_objects/Items/Heal_item.h"
#include "../On_cell_objects/Items/Damage_increase_item.h"
#include "../On_cell_objects/Enemies/Knight_enemy.h"
#include "../On_cell_objects/Enemies/Tiny_enemy.h"
#include "../On_cell_objects/Enemies/Ogre_enemy.h"
#include "Game_save.h"

class Json_to_data {
public:
//    ~Json_to_data();
    Json_to_data() = default;

    Game_save* get_game(nlohmann::json& json);

private:
};


