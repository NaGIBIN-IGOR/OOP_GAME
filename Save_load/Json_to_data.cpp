//
// Created by igor on 23.12.2021.
//
#include "Json_to_data.hpp"
Game_save* Json_to_data::get_game(nlohmann::json& json) {
    Game_save* game_save = new Game_save;
    game_save->difficulty = json["difficulty"].get<unsigned>();
    game_save->game_inf = {json["game_inf"]["dead_enemy_number"].get<unsigned>(),
                           json["game_inf"]["item_number"].get<unsigned>(),
                           json["game_inf"]["enemy_number"].get<unsigned>(),
                           json["game_inf"]["picked_up_item_number"].get<unsigned>(),
                           json["game_inf"]["turn_number"].get<unsigned>()};
    game_save->control_inf = {(json["control_inf"]["item_freq_gen"].get<unsigned>()),
                              json["control_inf"]["enemy_freq_gen"].get<unsigned>(),
                              json["control_inf"]["max_item_number"].get<unsigned>(),
                              (json["control_inf"]["max_enemy_number"].get<unsigned>())
    };

    Field *field = new Field();
    field->set_wide(json["field"]["wide"].get<unsigned>());
    field->set_height(json["field"]["height"].get<unsigned>());
    field->set_y_exit_coordinate(json["field"]["exit_coord"].get<unsigned>());
    field->set_y_entrance_coordinate(json["field"]["entrance_coord"].get<unsigned>());
    field->environment_exist_set();
    unsigned i = 0;
    for(nlohmann::json::iterator cells_array = json["field"]["cells"].begin(); cells_array != json["field"]["cells"].end(); ++cells_array){
        unsigned j = 0;
        for(nlohmann::json::iterator cell = cells_array->begin(); cell != cells_array->end(); ++cell){
            auto &f_cell = field->get_cell(j, i);
            f_cell.set_cell_type_inf((*cell)["cell_type_inf"].get<Type_cell>());
            f_cell.set_player(nullptr);
            f_cell.set_passable((*cell)["passable"].get<bool>());
            if ((*cell)["enemy"].is_object()) {
                Type_enemy tenemy = (*cell)["enemy"]["type"].get<Type_enemy>();
                Enemy *enemy = nullptr;
                if (tenemy == KNIGHT) {
                    enemy = new Knight_enemy(j, i, (*cell)["enemy"]["health"], (*cell)["enemy"]["damage"]);
                }
                else if (tenemy == OGRE){
                    enemy = new Ogre_enemy(j, i, (*cell)["enemy"]["health"], (*cell)["enemy"]["damage"]);
                }
                else if (tenemy == TINY){
                    enemy = new Tiny_enemy(j, i, (*cell)["enemy"]["health"], (*cell)["enemy"]["damage"]);
                }
                f_cell.set_enemy(enemy);
                game_save->enemies.push_back(enemy);
            }else f_cell.set_enemy(nullptr);
            if ((*cell)["item"].get<Type_item>() != NO_ITEM) {
                Type_item titem = (*cell)["item"].get<Type_item>();
                Item *item = nullptr;
                if (titem == HEAL){
                    item = new Heal_item;
                }
                else if (titem == DAMAGE_INCREASE){
                    item = new Damage_increase_item;
                }
                else if (titem == MAX_HEAL_DAMAGE_INCREASE){
                    item = new Max_health_damage_increase;
                }
                f_cell.set_item(item);
            } else f_cell.set_item(nullptr);
            ++j;
        }
        ++i;
    }

    game_save->field = field;

    Player *player = new Player;
    player->set_x_coordinate(json["player"]["x_player_coordinate"].get<unsigned>());
    player->set_y_coordinate(json["player"]["y_player_coordinate"].get<unsigned>());
    player->set_damage(json["player"]["damage"].get<unsigned>());
    player->set_health(json["player"]["health"].get<unsigned>());
    player->set_max_damage(json["player"]["max_damage"].get<unsigned>());
    player->set_max_health(json["player"]["max_health"].get<unsigned>());
    player->set_items_picked_up_number(json["player"]["picked_up_items"].get<unsigned>());
    field->get_cell(player->get_x_coordinate(), player->get_y_coordinate()).set_player(player);
    game_save->player = player;

    std::string row_win_cond = json["win condition"];
    std::string win_cond;
    if (row_win_cond.find("exit") != -1) {
        win_cond = "exit";
    }
    else if (row_win_cond.find("items") != -1) {
        win_cond = "items";
    }
    else{
        win_cond = "undef";
    }
    game_save->win_rule = win_cond;
    std::string close = json["input_commands"]["CLOSE_GAME"].get<std::string>();
    std::string down = json["input_commands"]["MOVE_DOWN"].get<std::string>();
    std::string left = json["input_commands"]["MOVE_LEFT"].get<std::string>();
    std::string right = json["input_commands"]["MOVE_RIGHT"].get<std::string>();
    std::string up = json["input_commands"]["MOVE_UP"].get<std::string>();
    std::string save = json["input_commands"]["SAVE_GAME"].get<std::string>();
    game_save->input_commands.push_back(std::pair(CLOSE_GAME, close));
    game_save->input_commands.push_back(std::pair(MOVE_DOWN, down));
    game_save->input_commands.push_back(std::pair(MOVE_LEFT, left));
    game_save->input_commands.push_back(std::pair(MOVE_RIGHT, right));
    game_save->input_commands.push_back(std::pair(MOVE_UP, up));
    game_save->input_commands.push_back(std::pair(SAVE_GAME, save));
    return game_save;
}

//Json_to_data::~Json_to_data() {
//    if(save) delete save;
//}
