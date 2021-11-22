//
// Created by igor on 18.10.2021.
//
#include "Cell_view.h"
#include "../Cell/Cell.h"

Cell_view::Cell_view(Cell &cell) : cell(cell) {
}

char Cell_view::get_cell_sign() const {
    Type_cell type = cell.get_cell_type_inf();

    if(cell.player_on_cell()) {
        return 'H';
    }
    else if(cell.item_on_cell()){
        switch (cell.get_item_type_inf()) {
            case MAX_HEAL_DAMAGE_INCREASE: return '&';
            case HEAL: return 'h';
            case DAMAGE_INCREASE: return 'd';

        }
    }
    else if(cell.enemy_on_cell()){
        switch (cell.get_enemy_type_inf()) {
            case OGRE: return '0';
            case KNIGHT: return 'k';
            case TINY: return 'o';

        }
    }
    switch (type) {
        case PASSABLE_CELL: return ' ';
        case WALL: return '#';
        case ENTRANCE: return '(';
        case EXIT: return ')';
        case UNDEFINED_CELL: return '?';
    }
    return '?';
}