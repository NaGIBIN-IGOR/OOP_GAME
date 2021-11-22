//
// Created by igor on 24.10.2021.
//

#include "Enemy.h"
#include "../../Cell/Cell.h"
#include "../../Field/Field.h"
#include "../Player.h"
#include "../../Logs/Logger.h"
#include <iostream>

void Enemy::move_left(Field &field) {

    Cell& current_cell = field.get_cell(x, y);

    if(field.get_cell(x - 1, y).is_passable()
        && field.get_cell(x - 1, y).get_cell_type_inf() == PASSABLE_CELL
        && !field.get_cell(x - 1, y).item_on_cell()
        && !field.get_cell(x-1, y).player_on_cell()
        && !field.get_cell(x-1, y).enemy_on_cell())
    {
        field.get_cell(x - 1, y).set_enemy(this);
        current_cell.remove_enemy();
        this->x -= 1;
    }
}

void Enemy::move_right(Field &field) {

    Cell& current_cell = field.get_cell(x, y);

    if(field.get_cell(x + 1, y).is_passable()
       && field.get_cell(x + 1, y).get_cell_type_inf() == PASSABLE_CELL
       && !field.get_cell(x + 1, y).item_on_cell()
       && !field.get_cell(x + 1, y).player_on_cell()
       && !field.get_cell(x + 1, y).enemy_on_cell())
    {
        field.get_cell(x + 1, y).set_enemy(this);
        current_cell.remove_enemy();
        this->x += 1;
    }
}

void Enemy::move_up(Field &field) {
    Cell& current_cell = field.get_cell(x, y);

    if(field.get_cell(x, y - 1).is_passable()
       && field.get_cell(x, y - 1).get_cell_type_inf() == PASSABLE_CELL
       && !field.get_cell(x, y - 1).item_on_cell()
       && !field.get_cell(x, y - 1).player_on_cell()
       && !field.get_cell(x, y - 1).enemy_on_cell())
    {
        field.get_cell(x, y - 1).set_enemy(this);
        current_cell.remove_enemy();
        this->y -= 1;
    }
}

void Enemy::move_down(Field &field) {
    Cell& current_cell = field.get_cell(x, y);

    if(field.get_cell(x, y + 1).is_passable()
       && field.get_cell(x, y + 1).get_cell_type_inf() == PASSABLE_CELL
       && !field.get_cell(x, y + 1).item_on_cell()
       && !field.get_cell(x, y + 1).player_on_cell()
       && !field.get_cell(x, y + 1).enemy_on_cell())
    {
        field.get_cell(x, y + 1).set_enemy(this);
        current_cell.remove_enemy();
        this->y += 1;
    }
}

void Enemy::make_move(Field &field, Diraction dir) {
    switch (dir) {
        case UP:
            move_up(field);
            break;
        case DOWN:
            move_down(field);
            break;
        case LEFT:
            move_left(field);
            break;
        case RIGHT:
            move_right(field);
            break;
    }
}

void Enemy::make_hit(Player& player) {
//    Logger().message("Враг наносит урон" + std::to_string(get_damage()) + "ед.урона", "../../Logs/Logs.txt");
    if((int)player.get_health() - (int)get_damage() < 0) player.set_health(0);
    else player.set_health(player.get_health() - get_damage());
}

void Enemy::take_hit(unsigned int dmg) {
//    Logger().message("Враг получает урон" + std::to_string(dmg) + "ед.урона", "../../Logs/Logs.txt");
    if((int) get_health() - (int)dmg < 0) set_health(0);
    else set_health(get_health() - dmg);

}

void Enemy::print(std::ostream &out) {
    out<<*this;
}

std::ostream &operator<<(std::ostream &out,  Enemy &enemy) {
    enemy.print_enemy_inf(out);
    return out;
}

