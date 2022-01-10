//
// Created by igor on 23.12.2021.
//

#pragma once
#include "Game_save.h"
#include "../Conditions/Lose_condition.h"
#include "../Conditions/Win_condition_items.h"
#include "../Conditions/Win_condition_exit.h"
#include "../Game/Game.h"
#include "../Game/Message_to_user.h"

class Game_loader {
public:
    Game_loader(Game_save* save);
    ~Game_loader();
    void start_load_game();

private:
    Game_save* save_struct;
};

void Game_loader::start_load_game() {
    if(save_struct->win_rule == "exit"){
        Game<Win_condition_exit<1>, Lose_condition<1>> game(save_struct);
        game.start();
    }
    else if(save_struct->win_rule == "items"){
        Game<Win_condition_items<1>, Lose_condition<1>> game(save_struct);
        game.start();
    }
    else{
        Message_to_user::message("Не корректное правило");
    }

}

Game_loader::Game_loader(Game_save *save) : save_struct(save) {

}

Game_loader::~Game_loader() {
    delete save_struct->field;
    delete save_struct->player;
    delete save_struct;
}


