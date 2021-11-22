//
// Created by igor on 18.10.2021.
//

#ifndef OOPGAME_FIELD_GENERATE_H
#define OOPGAME_FIELD_GENERATE_H

#include "Field.h"


class Enemy; class Item;

class Field_generate {
public:
    Field_generate() = default;

    bool environment_generate(Field& field);
    Item* add_rand_item(Field& field);
    Enemy* add_rand_enemy(Field& field);
private:

    void enter_exit_generate(Field& field);

    void floor_generate(Field& field);

    void wall_generate(Field& field);

    unsigned x_rand_coord_generate(Field& field);

    unsigned y_rand_coord_generate(Field& field);
    // filed.get_cell(x_rand_coord_generate(), y_rand_coord_generate()) - passable cell, not a exit

};

#endif //OOPGAME_FIELD_GENERATE_H
