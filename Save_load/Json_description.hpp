//
// Created by igor on 21.12.2021.
//

#pragma once
#include "json.hpp"
#include "../Game/Game.h"
#include "../Game/Input_command.h"
#include <typeinfo>

class Cell;class Field;class Player;class Enemy;class Item;
class Json_description {
public:
    template<typename win_rule, typename lose_rule>
    nlohmann::json to_json(Game<win_rule, lose_rule> &game);
    nlohmann::json to_json(Field& field);
    nlohmann::json to_json(Cell& cell);
    nlohmann::json to_json(Player& player);
    nlohmann::json to_json(Enemy& enemy);
};


template<typename win_rule, typename lose_rule>
nlohmann::json Json_description::to_json(Game<win_rule, lose_rule> &game) {
    nlohmann::json  json_game{};
    win_rule win_condition;
    lose_rule lose_condition;
    json_game["difficulty"] = game.get_difficulty();
    json_game["field"] = to_json(game.get_field());
    json_game["player"] = to_json(game.get_player());
    json_game["win condition"] = typeid(win_condition).name();
    json_game["lose condition"] = typeid(lose_condition).name();
    json_game["game_inf"] = {
            {"item_number" , game.get_game_inf().item_number},
            {"dead_enemy_number", game.get_game_inf().dead_enemy_number},
            {"picked_up_item_number", game.get_game_inf().picked_up_item_number},
            {"turn_number", game.get_game_inf().turn_number},
            {"enemy_number", game.get_game_inf().enemy_number}
    };
    json_game["control_inf"] = {
            {"item_freq_gen", game.get_control_inf().item_freq_gen},
            {"enemy_freq_gen", game.get_control_inf().enemy_freq_gen},
            {"max_enemy_number", game.get_control_inf().max_enemy_number},
            {"max_item_number", game.get_control_inf().max_item_number}
    };
    json_game["input_commands"] = {
            {"MOVE_UP", game.get_input_command().get_command(MOVE_UP)},
            {"MOVE_DOWN", game.get_input_command().get_command(MOVE_DOWN)},
            {"MOVE_RIGHT", game.get_input_command().get_command(MOVE_RIGHT)},
            {"MOVE_LEFT", game.get_input_command().get_command(MOVE_LEFT)},
            {"CLOSE_GAME", game.get_input_command().get_command(CLOSE_GAME)},
            {"SAVE_GAME", game.get_input_command().get_command(SAVE_GAME)}
    };
    return json_game;
}