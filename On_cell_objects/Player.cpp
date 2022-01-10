//
// Created by igor on 19.10.2021.
//
#include "Player.h"
#include "../Field/Field.h"
#include "Enemies/Enemy.h"
#include "Items/Item.h"
#include "../Cell/Cell.h"
#include "../Enums/Command.h"

#include <sstream>

unsigned Player::get_max_damage() const {
    return max_damage;
}

void Player::set_max_damage(unsigned max_dmg) {
    max_damage = max_dmg;
}

unsigned Player::get_max_health() const {
    return max_health;
}
void Player::set_max_health(unsigned max_hp) {
    max_health = max_hp;
}
unsigned Player::get_x_coordinate()  {
    return x_player_coordinate;
}

unsigned Player::get_y_coordinate()  {
    return y_player_coordinate;
}

void Player::set_x_coordinate(unsigned int x) {
    this->x_player_coordinate = x;
}

void Player::set_y_coordinate(unsigned int y) {
    this->y_player_coordinate = y;
}

unsigned Player::get_health()  {
    return health;
}

unsigned Player::get_damage()  {
    return damage;
}

void Player::set_health(unsigned int health) {
    this->health = health;
}

void Player::set_damage(unsigned int damage) {
    this->damage = damage;
}

void Player::move_up(Field &field) {
    if (y_player_coordinate - 1 > 0) {
        Cell &cell = field.get_cell(x_player_coordinate, y_player_coordinate - 1);
        if(cell.enemy_on_cell()){
            make_hit(cell.get_enemy());
            if(cell.get_enemy().get_health() == 0){
                cell.remove_enemy();
            }
        }
        else if (cell.is_passable() && cell.get_cell_type_inf() == PASSABLE_CELL) {
            field.get_cell(x_player_coordinate, y_player_coordinate).remove_player();
            cell.set_player(this);
            y_player_coordinate -= 1;
            if(cell.get_item_type_inf() != NO_ITEM){
                cell.get_item().pick_up_item(*this, cell);
                ++picked_up_items;
            }
        }
    }
}

void Player::move_down(Field &field) {
    if(y_player_coordinate+1 < field.get_height()-1) {
        Cell &cell = field.get_cell(x_player_coordinate, y_player_coordinate +1);
        if(cell.enemy_on_cell()){
            make_hit(cell.get_enemy());
            if(cell.get_enemy().get_health() == 0){
                cell.remove_enemy();
            }
        }
        else if (cell.is_passable() && cell.get_cell_type_inf() == PASSABLE_CELL) {
            field.get_cell(x_player_coordinate, y_player_coordinate).remove_player();
            cell.set_player(this);
            y_player_coordinate += 1;
            if(cell.get_item_type_inf() != NO_ITEM){
                cell.get_item().pick_up_item(*this, cell);
                ++picked_up_items;

            }
        }
    }
}

void Player::move_left(Field &field) {
    Cell &cell = field.get_cell(x_player_coordinate - 1, y_player_coordinate);
    if(cell.enemy_on_cell()){
        make_hit(cell.get_enemy());
        if(cell.get_enemy().get_health() == 0) {
            cell.remove_enemy();
        }
    }
    else if (cell.is_passable() && cell.get_cell_type_inf() == PASSABLE_CELL) {
        field.get_cell(x_player_coordinate, y_player_coordinate).remove_player();
        cell.set_player(this);
        x_player_coordinate -= 1;
        if(cell.get_item_type_inf() != NO_ITEM){
            cell.get_item().pick_up_item(*this, cell);
            ++picked_up_items;

        }
    }
}
void Player::move_right(Field &field) {
    Cell &cell = field.get_cell(x_player_coordinate + 1, y_player_coordinate);
    if(cell.enemy_on_cell()){
        make_hit(cell.get_enemy());
        if(cell.get_enemy().get_health() == 0) {
            cell.remove_enemy();
        }
    }
    else if (cell.is_passable() && (cell.get_cell_type_inf() == PASSABLE_CELL || cell.get_cell_type_inf() == EXIT)) {
        field.get_cell(x_player_coordinate, y_player_coordinate).remove_player();
        cell.set_player(this);
        x_player_coordinate += 1;
        if(cell.get_item_type_inf() != NO_ITEM){
            cell.get_item().pick_up_item(*this, cell);
            ++picked_up_items;

        }
    }
}

void Player::make_hit(Enemy &enemy) {

    std::stringstream ss;
    ss << "\t" << "Игрок наносит " << this->damage << "ед.урона: " << enemy << std::endl;
    enemy.take_hit(get_damage());
}
void Player::make_move(Field& field, Command c) {
    switch (c) {
        case MOVE_UP:
            move_up(field);
            return;
        case MOVE_LEFT:
            move_left(field);
            return;
        case MOVE_DOWN:
            move_down(field);
            return;
        case MOVE_RIGHT:
            move_right(field);
            return;
        default:
            return;
    }

}
void Player::make_move(Field& field, char wasd) {
    switch (wasd) {
        case 'w':
            move_up(field);
            return;
        case 'a':
            move_left(field);
            return;
        case 's':
            move_down(field);
            return;
        case 'd':
            move_right(field);
            return;
    }

}

std::ostream &operator<<(std::ostream &out,  const Player &player) {
    out << "Игрок";
    return out;
}

unsigned Player::get_x_coordinate() const {
    return x_player_coordinate;
}

unsigned Player::get_y_coordinate() const {
    return y_player_coordinate;
}

unsigned Player::get_health() const {
    return health;
}

unsigned Player::get_damage() const {
    return damage;
}

void Player::print(std::ostream &out){
    out << *this;
}

unsigned Player::get_items_pick_up_number() {
    return picked_up_items;
}

void Player::set_items_picked_up_number(unsigned int num) {
    picked_up_items = num;
}





