//
// Created by igor on 18.10.2021.
//
#include "Cell.h"
#include "../View/Cell_view.h"
#include "../On_cell_objects/Player.h"
#include "../On_cell_objects/Items/Item.h"
#include "../On_cell_objects/Enemies/Enemy.h"

Cell::Cell() : passable(false), cell_type_inf(UNDEFINED_CELL) {
}

Cell::Cell(bool passible, Type_cell type) : passable(passable), cell_type_inf(type) {
}

Cell::Cell(const Cell &reference_cell) : passable(reference_cell.passable),
                                         cell_type_inf(reference_cell.cell_type_inf) {
}

Cell::~Cell() {
}

bool Cell::is_passable() const {
    return this->passable;
}

void Cell::set_player(Player *player) {
    if (passable && cell_type_inf != WALL) {
        this->player = player;
    } else return;
}

void Cell::remove_player() {
    this->player = nullptr;

}

void Cell::set_cell_type_inf(Type_cell type) {
    cell_type_inf = type;
}

Type_cell Cell::get_cell_type_inf() {
    return cell_type_inf;
}

void Cell::set_passable(bool pass) {
    passable = pass;
}

bool Cell::player_on_cell() {
    if (player != nullptr) {
        return true;
    }
    return false;
}

void Cell::set_item(Item *item) {
    this->item = item;
}

void Cell::remove_item() {
    if(item != nullptr) {
        delete this->item;
        this->item = nullptr;
    }
}


Type_item Cell::get_item_type_inf() {
    if(item_on_cell()){
        return item->get_item_type();
    }
    else{
        return NO_ITEM;
    }
}

Type_enemy Cell::get_enemy_type_inf() {
    if(enemy_on_cell()){
        return enemy->get_enemy_type();
    }
    else{
        return NO_ENEMY;
    }
}

bool Cell::enemy_on_cell() {
    if (enemy != nullptr) {
        return true;
    }
    return false;
}
bool Cell::item_on_cell() {
    if(item != nullptr){
        return true;
    }
    return false;
}
//void Cell::pick_up_item(Player& player) {
//    item->pick_up_item(player, *this);
//}
Enemy& Cell::get_enemy() {
    if (enemy_on_cell()) {
        return *enemy;
    }
}

void Cell::set_enemy(Enemy* en) {
    enemy = en;
}
void Cell::remove_enemy(){
//    delete enemy;
    enemy = nullptr;
}

Player &Cell::get_player() {
    return *player;
}
Item &Cell::get_item(){
    return *item;
}