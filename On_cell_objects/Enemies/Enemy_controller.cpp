//
// Created by igor on 24.10.2021.
//

#include <iostream>
#include "Enemy_controller.h"
#include "../../Cell/Cell.h"
#include "../../Field/Field.h"




void Enemy_controller::make_action(std::vector<Enemy*>& enemies, Field &field) {
    for (int i = 0; i < enemies.size(); ++i) {
        if (enemies[i]->get_health() == 0) {
            delete enemies[i];
            enemies.erase(enemies.begin() + i);
            continue;
        }
        Enemy &enemy = *(enemies[i]);
        unsigned w = enemy.get_x_coordinate();
        unsigned h = enemy.get_y_coordinate();
        Diraction player_diraction = player_check(field, w, h);
        if (enemy.get_enemy_type() == KNIGHT || enemy.get_enemy_type() == TINY) {
            if (player_diraction == UNDEFINED_DIRACTON) {
                unsigned rand_diraction = rand() % 4;
                enemy.make_move(field, Diraction(rand_diraction));
            } else if (player_diraction == UPPER_RIGHT || player_diraction == UPPER_LEFT) {
                enemy.make_move(field, UP);
            } else if (player_diraction == LOWER_RIGHT || player_diraction == LOWER_LEFT) {
                enemy.make_move(field, DOWN);
            }
        }
        switch (player_diraction) {
            case UP:
                enemy.make_hit(field.get_cell(w, h - 1).get_player());
                break;
            case DOWN:
                enemy.make_hit(field.get_cell(w, h + 1).get_player());
                break;
            case LEFT:
                enemy.make_hit(field.get_cell(w - 1, h).get_player());
                break;
            case RIGHT:
                enemy.make_hit(field.get_cell(w + 1, h).get_player());
                break;

        }
    }
}


Diraction Enemy_controller::player_check(Field &field, unsigned int x, unsigned int y) {
    if (x - 1 > 0 && field.get_cell(x - 1, y).player_on_cell()) {
        return LEFT;
    } else if (x + 1 < field.get_height() && field.get_cell(x + 1, y).player_on_cell()) {
        return RIGHT;
    } else if (y + 1 > 0 && field.get_cell(x, y + 1).player_on_cell()) {
        return DOWN;
    } else if (y - 1 < field.get_height() && field.get_cell(x, y - 1).player_on_cell()) {
        return UP;
    } else if (x - 1 > 0 && y + 1 < field.get_height() && field.get_cell(x - 1, y + 1).player_on_cell()) {
        return LOWER_LEFT;
    } else if (x + 1 > 0 && y + 1 < field.get_height() && field.get_cell(x + 1, y + 1).player_on_cell()) {
        return LOWER_RIGHT;
    } else if (x - 1 > 0 && y - 1 < field.get_height() && field.get_cell(x - 1, y - 1).player_on_cell()) {
        return UPPER_LEFT;
    } else if (x + 1 > 0 && y - 1 < field.get_height() && field.get_cell(x + 1, y - 1).player_on_cell()) {
        return UPPER_RIGHT;
    } else {
        return UNDEFINED_DIRACTON;
    }
}

//void Enemy_controller::append_enemy(Enemy *enemy) {
//    if (enemy) enemies.push_back(enemy);
//    else return;
//}

