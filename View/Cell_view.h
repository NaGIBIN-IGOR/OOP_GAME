//
// Created by igor on 18.10.2021.
//

#ifndef OOPGAME_CELL_VIEW_H
#define OOPGAME_CELL_VIEW_H

#include "../Enums/Type_cell.h"

class Cell;

class Cell_view {
public:
    Cell_view(Cell &cell);

    char get_cell_sign() const;

private:
    Cell &cell;
};

#endif //OOPGAME_CELL_VIEW_H
