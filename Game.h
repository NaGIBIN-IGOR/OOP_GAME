//
// Created by igor on 20.10.2021.
//

#pragma once



#include "vector"
#include "Logs/Watcher.h"

class Field; class Field_view; class Field_generate; class Enemy_controller; class Player; class Enemy;

class Game{
public:
    Game();
    ~Game();
    void start();
private:
    Field* field;
    Field_view* view_field;
    Field_generate* gen_field;
    Enemy_controller* enemy_controller ;
    Player* player;
    std::vector<Enemy*> enemies;

    void end();
    bool check_player_death();
    bool player_on_exit();
    void print_player_stats();
    void delete_dead_enemies();
};
 //OOPGAME_GAME_H