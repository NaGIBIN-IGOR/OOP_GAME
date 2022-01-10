//
// Created by igor on 20.10.2021.
//

#include <iostream>
#include "Game.h"
#include "../Field/Field_generate.h"
#include "../View/Field_view.h"
#include "../On_cell_objects/Enemies/Enemy_controller.h"
#include "../Cell/Cell.h"
#include "../Clear_terminal.h"
#include "../Logs/Logger/Logger.h"
#include "../On_cell_objects/Items/Item.h"
#include "Input_command.h"
#include "../Save_load/Save_game.hpp"
#include "Message_to_user.h"
#include "../Save_load/Load_game.hpp"

template<typename win_rule, typename lose_rule>
Game<win_rule, lose_rule>::Game(unsigned difficulty):
        field(new Field(17, 5)),
        enemy_controller(new Enemy_controller()),
        view_field(new Field_view()),
        gen_field(new Field_generate()),
        player(new Player()),
        input_command(new Input_command()),
        difficulty(difficulty) {
    std::srand(time(nullptr));
    gen_field->environment_generate(*field);
    control_inf = {3, 5, 2 * 8 + 1, 2 * 6 + 1};
    input_command->set_command(CLOSE_GAME, "1=");
    input_command->set_command(MOVE_DOWN, "sk");
    input_command->set_command(MOVE_UP, "wi");
    input_command->set_command(MOVE_LEFT, "aj");
    input_command->set_command(MOVE_RIGHT, "dl");
    input_command->set_command(SAVE_GAME, "\\");
    player->set_x_coordinate(1);
    player->set_y_coordinate(field->get_entrance_coordinate());
    field->get_cell(player->get_x_coordinate(), field->get_entrance_coordinate()).set_player(player);

}

//template<unsigned difficulty>
template<typename win_rule, typename lose_rule>
Game<win_rule, lose_rule>::Game(Game_save *game_save):
        difficulty(game_save->difficulty),
        field(game_save->field),
        view_field(new Field_view()),
        gen_field(new Field_generate()),
        enemy_controller(new Enemy_controller()),
        player(game_save->player) {
    save_flag = true;
    enemies = game_save->enemies;
    game_inf = game_save->game_inf;
    control_inf = game_save->control_inf;
    input_command = new Input_command();
    for (auto pair: game_save->input_commands) {
        input_command->set_command(pair.first, pair.second);
    }


}

//template<unsigned difficulty>
//template<Win_condition* win_rule, Condition* lose_rule>
template<typename win_rule, typename lose_rule>
Game<win_rule, lose_rule>::~Game() {
    delete enemy_controller;
    delete view_field;
    delete gen_field;
    delete input_command;
    for (auto *enemy: enemies) {
        delete enemy;
    }
    if (!save_flag) {
        delete field;
        delete player;

    }
}

//template<unsigned difficulty>
//template<Win_condition* win_rule, Condition* lose_rule>
template<typename win_rule, typename lose_rule>
void Game<win_rule, lose_rule>::start() {
    if (difficulty == -1) return;
    if (!field->is_environment_exist()) exit(1);


    Clear_terminal::clear_screen();
    view_field->display(*field);
    Message_to_user::print_player_stats(*player);
    Save_game sv;


    Clear_terminal::set_terminal_icanon();
    Clear_terminal::clear_terminal_icanon();
    while (true) {
        Command com = input_command->command_from_input();
        if (com == CLOSE_GAME) {
            break;
        }
        else if (com == SAVE_GAME){
            Message_to_user::ask_player_for_save_num();
            unsigned save = -1;
            std::cin >> save;
            sv.save_game(*this, save);
           show_game();
            continue;
        }
        ++game_inf.turn_number;
        player->make_move(*field, com);

        if (check_win_condition()) break;
        enemy_controller->make_action(enemies, *field);
        if (check_lose_condition()) break;
        if (game_inf.turn_number % control_inf.item_freq_gen == 0 &&
            game_inf.item_number < control_inf.max_item_number) {
            auto *item = gen_field->add_rand_item(*field);
            if (item) {
                ++game_inf.item_number;
            }
        }
        if (game_inf.turn_number % control_inf.enemy_freq_gen == 0 &&
            game_inf.enemy_number < control_inf.max_enemy_number) {
            auto *enemy = gen_field->add_rand_enemy(*field);
            if (enemy) {
                if (enemy->get_enemy_type() == TINY) {
                }
                enemies.push_back(enemy);
                ++game_inf.enemy_number;
            }
        }

        show_game();


        delete_dead_enemies();
        game_inf.picked_up_item_number = player->get_items_pick_up_number();
        Clear_terminal::clear_terminal_icanon();
    }
}

//template<Win_condition* win_rule, Condition* lose_rule>

//template<unsigned difficulty>
//template<Win_condition* win_rule, Condition* lose_rule>
template<typename win_rule, typename lose_rule>
bool Game<win_rule, lose_rule>::check_lose_condition() {
    if (player->get_health() == 0) {
        if (lose_condition.is_met(*player, game_inf, *field)) {
            show_game();
            Message_to_user::end();
            std::cout << "\t\tLose condition complete\n";
        }
        std::cout << "\t\tWASTED\n";
        return true;
    }
    return false;
}


//template<unsigned difficulty>
//template<Win_condition* win_rule, Condition* lose_rule>
template<typename win_rule, typename lose_rule>
bool Game<win_rule, lose_rule>::check_win_condition() {
    if (player->get_x_coordinate() == field->get_wide() - 1 &&
        player->get_y_coordinate() == field->get_exit_coordinate()) {
        if (win_condition.is_met(*player, game_inf, *field)) {
            show_game();
            std::cout << "\t\tYOU WIN\t\t\n";
            Message_to_user::end();
            return true;
        } else player->move_left(*field);
    }
    return false;
}


template<typename win_rule, typename lose_rule>
void Game<win_rule, lose_rule>::delete_dead_enemies() {
    int i = 0;
    for (auto *enemy: enemies) {
        if (enemy->get_health() == 0) {
            delete enemy;
            enemies.erase(enemies.begin() + i);
            ++game_inf.dead_enemy_number;
            continue;
        }
        i++;
    }
}

template<typename win_rule, typename lose_rule>
Field &Game<win_rule, lose_rule>::get_field() {
    return *field;
}

template<typename win_rule, typename lose_rule>
Player &Game<win_rule, lose_rule>::get_player() {
    return *player;
}

template<typename win_rule, typename lose_rule>
Game_inf &Game<win_rule, lose_rule>::get_game_inf() {
    return game_inf;
}

template<typename win_rule, typename lose_rule>
Game_control_inf &Game<win_rule, lose_rule>::get_control_inf() {
    return control_inf;
}

template<typename win_rule, typename lose_rule>
Input_command &Game<win_rule, lose_rule>::get_input_command() {
    return *input_command;
}

template<typename win_rule, typename lose_rule>
unsigned Game<win_rule, lose_rule>::get_difficulty() {
    return difficulty;
}

template<typename win_rule, typename lose_rule>
Game_save* Game<win_rule, lose_rule>::prepare_start() {
    Message_to_user::ask_player_to_load_game();
    int choice = 99;
    std::cin >> choice;
    if(choice == 1) {
        Message_to_user::ask_player_save_num();
        std::cin >> choice;
        Load_game load;
        try {
            Game_save *gameSave = load.load_game(choice);
            return gameSave;

        }
        catch (const char *ex){
            Message_to_user::message(static_cast<std::string> (ex));
        }
    }
    else if(choice == 2) {
        this->start();
        return nullptr;
    }
    else{
        Message_to_user::message( "Некорректный выбор");
        return nullptr;
    }
}

template<typename win_rule, typename lose_rule>
void Game<win_rule, lose_rule>::show_game() {
    Clear_terminal::clear_screen();
    view_field->display(*field);
    Message_to_user::print_player_stats(*player);
}

