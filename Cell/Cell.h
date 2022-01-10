//
// Created by igor on 18.10.2021.
//

#pragma once

#include "../View/Cell_view.h"
#include "../Enums/Type_cell.h"
#include "../Enums/Type_item.h"
#include "../Enums/Type_enemy.h"

class Item;
class Enemy;
class Player;

class Cell {
public:
    Cell();

    Cell(bool passable, Type_cell type);

    ~Cell();

    Cell(const Cell &reference_cell);

    bool is_passable() const;

    bool player_on_cell();

    bool enemy_on_cell();

    bool item_on_cell();

    Type_cell get_cell_type_inf();

    Type_item get_item_type_inf();

    Type_enemy get_enemy_type_inf();

    Player& get_player();

    Enemy& get_enemy();

    Item& get_item();

    void set_passable(bool pass);

    void set_cell_type_inf(Type_cell type);

    void set_player(Player *player);

    void set_item(Item* item);

    void set_enemy(Enemy*);

    void remove_player();

    void remove_enemy();

    void remove_item();

    //void pick_up_item(Player& player);

private:
    bool passable;
    Type_cell cell_type_inf;

    Player *player = nullptr;
    Item *item = nullptr;
    Enemy *enemy = nullptr;
};

 //OOPGAME_CELL_H
