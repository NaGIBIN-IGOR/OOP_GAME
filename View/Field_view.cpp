//
// Created by igor on 18.10.2021.
//

#include <iostream>
#include "Field_view.h"
#include "../Field/Field.h"
#include <SFML//Graphics.hpp>
#include "Cell_view.h"

void Field_view::display(const Field &field) {
    for (unsigned int y = 0; y < field.get_height(); y++) {
        for (unsigned int x = 0; x < field.get_wide(); x++) {
            Cell_view view_cell(field.get_cell(x, y));
            std::cout << view_cell.get_cell_sign();
        }
        std::cout << '\n';
    }
}