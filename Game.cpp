//
// Created by igor on 20.10.2021.
//

#include <iostream>
#include "Game.h"
#include "Field/Field.h"
#include "Field/Field_generate.h"
#include "View/Field_view.h"
#include "On_cell_objects/Player.h"
#include "On_cell_objects/Enemies/Enemy_controller.h"
#include "Cell/Cell.h"
#include "Clear_terminal.h"
#include "Logs/Logger.h"


#define ITEM_FREQ_GENERATE 2
#define ENEMY_FREQ_GENERATE 3
#define MAX_ITEM_NUMBER 10
#define MAX_ENEMY_NUMBER 6

Game::Game():field(new Field(20, 7)), enemy_controller(new Enemy_controller()), view_field(new Field_view()), gen_field(new Field_generate()), player(new Player()), observer(new Observer()){
    std::srand(time(nullptr));
    gen_field->environment_generate(*field);
}

Game::~Game() {
    delete field;
    delete enemy_controller;
    delete view_field;
    delete gen_field;
    delete player;
    delete observer;
    for (Enemy* enemy: enemies) {
        delete enemy;
    }
}

void Game::start() {

    if(!field->is_environment_exist()) exit(1);
    player->set_x_coordinate(1);
    player->set_y_coordinate(field->get_entrance_coordinate());
    field->get_cell(player->get_x_coordinate(), field->get_entrance_coordinate()).set_player(player);


    Clear_terminal::clear_screen();
    view_field->display(*field);
    print_player_stats();

    Logger logger("../Logs/Logs.txt");
    char move_direction;
    unsigned move_number = 1;
    unsigned item_number = 0;
    unsigned enemy_number = 0;

    if(Logger::is_outf()) {
        Logger::message("Игра началась\n");
    }
    observer->add_observer(player);
    while (true){
        Logger::message("Ход номер " + std::to_string(move_number) + ":\n\n");

        if(check_player_death()) break;

        Clear_terminal::clear_terminal_icanon();

        std::cin >> move_direction;
        if(move_direction == '1') break;
        player->make_move(*field, move_direction);
        if(player_on_exit()) break;

        delete_dead_enemies();
        enemy_controller->make_action(enemies, *field);
        if(move_number % ITEM_FREQ_GENERATE == 0 && item_number < MAX_ITEM_NUMBER){
            auto* item = gen_field->add_rand_item(*field);
            if(item){
                ++item_number;
            }
        }
        if(move_number % ENEMY_FREQ_GENERATE == 0 && enemy_number < MAX_ENEMY_NUMBER){
            auto* enemy = gen_field->add_rand_enemy(*field);
            if(enemy) {
                if(enemy->get_enemy_type() == TINY){
                    observer->add_observer(enemy);
                }
                enemies.push_back(enemy);
                ++enemy_number;
            }
        }
        ++move_number;
        Clear_terminal::clear_screen();
        view_field->display(*field);
        print_player_stats();
        observer->check_subscribers();
    }
    Clear_terminal::set_terminal_icanon();
    Logger::message("Игра окончена");
}
void Game::end() {
    std::cout<<"\t\tTHE END\t\t\n";
}

bool Game::check_player_death() {
    if(player->get_health() == 0){
        end();
        std::cout<<"\t\tWASTED\n";
        return true;
    }
    return false;
}

bool Game::player_on_exit() {
    if(player->get_x_coordinate() == field->get_wide()-1 && player->get_y_coordinate() == field->get_exit_coordinate()){
        end();
        return true;
    }
    return false;
}

void Game::print_player_stats() {
    std::cout<<*player<<' '<< player->get_health() << " hp " << player->get_damage() << " dmg\n";
}

void Game::delete_dead_enemies() {
    int i = 0;
    for(auto* enemy: enemies){
        if(enemy->get_health() == 0){
            observer->remove_dead_subs();
            delete enemy;
            enemies.erase(enemies.begin()+i);
            continue;
        }
        i++;
    }

}
