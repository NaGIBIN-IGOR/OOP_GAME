//
// Created by igor on 21.12.2021.
//

#include "Json_description.hpp"
#include "../Cell/Cell.h"
#include "../On_cell_objects/Player.h"
#include "../On_cell_objects/Items/Item.h"
#include "../On_cell_objects/Enemies/Enemy.h"
#include "../Field/Field.h"

nlohmann::json Json_description::to_json(Cell &cell) {
    nlohmann::json json_cell{};
    json_cell["passable"] = cell.is_passable();
    json_cell["cell_type_inf"] = cell.get_cell_type_inf();
//    if (cell.player_on_cell()) json_cell["player"] = to_json(cell.get_player());
    json_cell["player"] = nullptr;
    if (cell.item_on_cell()) json_cell["item"] = cell.get_item().get_item_type();
    else json_cell["item"] = NO_ITEM;
    if (cell.enemy_on_cell()) json_cell["enemy"] = this->to_json(cell.get_enemy());
    else json_cell["enemy"] = NO_ENEMY;

    return json_cell;
}

nlohmann::json Json_description::to_json(Player &player) {
    nlohmann::json json_player{};
    json_player["health"] = player.get_health();
    json_player["max_health"] = player.get_max_health();
    json_player["damage"] = player.get_damage();
    json_player["max_damage"] = player.get_max_damage();
    json_player["x_player_coordinate"] = player.get_x_coordinate();
    json_player["y_player_coordinate"] = player.get_y_coordinate();
    json_player["picked_up_items"] = player.get_items_pick_up_number();
    return json_player;
}

nlohmann::json Json_description::to_json(Enemy &enemy) {
    nlohmann::json json_enemy{};
//    json_enemy["x"] = enemy.get_x_coordinate();
//    json_enemy["y"] = enemy.get_y_coordinate();
    json_enemy["health"] = enemy.get_health();
    json_enemy["damage"] = enemy.get_damage();
    json_enemy["type"] = enemy.get_enemy_type();
    return json_enemy;
}

nlohmann::json Json_description::to_json(Field &field) {
    nlohmann::json json_field{};
    json_field["wide"] = field.get_wide();
    json_field["height"] = field.get_height();
    json_field["environment_exist"] = field.is_environment_exist();
    json_field["entrance_coord"] = field.get_entrance_coordinate();
    json_field["exit_coord"] = field.get_exit_coordinate();

    nlohmann::json cells = nlohmann::json::array();
    for (size_t i = 0; i < field.get_height(); i++) {
        nlohmann::json tmp = nlohmann::json::array();
        for (size_t j = 0; j < field.get_wide(); j++) {
            tmp.push_back(to_json(field.get_cell(j, i)));
        }
        cells.push_back(tmp);
    }
    json_field["cells"] = cells;
    return  json_field;
}




