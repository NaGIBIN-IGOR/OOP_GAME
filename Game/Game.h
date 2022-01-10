//
// Created by igor on 20.10.2021.
//

#pragma once

#include <vector>
#include "Game_inf.h"
#include "Game_control_inf.h"
#include "Command_chars.h"
#include "../Save_load/Game_save.h"

class Field; class Field_view; class Field_generate; class Enemy_controller; class Player; class Enemy; class Item;

 class Input_command;

 template<typename  win_rule, typename lose_rule>
class Game{
public:
    Game()=default;
    Game(Game_save* game_save);
    Game(unsigned difficulty);
    ~Game();
    void start();
    Game_save* prepare_start();
    Field& get_field();
    Player& get_player();
    Game_inf& get_game_inf();
    Game_control_inf& get_control_inf();
    Input_command& get_input_command();
    unsigned get_difficulty();

private:
    unsigned difficulty = -1;
    Field* field = nullptr;
    Field_view* view_field = nullptr;
    Field_generate* gen_field = nullptr;
    Enemy_controller* enemy_controller  = nullptr;
    Player* player = nullptr;
    std::vector<Enemy*> enemies;
    Game_inf game_inf= {0,0,0,0};
    Game_control_inf control_inf = {0,0,0,0,};
    Input_command* input_command= nullptr;
    win_rule win_condition;
    lose_rule lose_condition;
    bool save_flag = false;

    bool check_lose_condition();
    bool check_win_condition();
    void delete_dead_enemies();
    void show_game();
};
 //OOPGAME_GAME_H