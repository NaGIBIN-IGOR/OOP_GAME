//
// Created by igor on 18.10.2021.
//

#include <cstring>
#include <memory>
#include "../Cell/Cell.h"
#include "Field.h"

Field::Field(unsigned int wide, unsigned int height) : wide(wide), height(height) {
    if (wide <= 3 || height <= 3) {
        this->wide = 0;
        this->height = 0;
        this->cells = nullptr;
    }
    else {
        cells = new Cell *[height];
        for (size_t i = 0; i < this->height; i++) {
            cells[i] = new Cell[wide];
        }
    }
}

Field::Field(const Field &reference_field) :
    wide(reference_field.wide),
    height(reference_field.height),
    environment_exist(reference_field.environment_exist),
    entrance_coord(reference_field.entrance_coord),
    exit_coord(reference_field.exit_coord)

    {
    this->cells = new Cell* [height];
    for (size_t i = 0; i < height; i++) {
        cells[i] = new Cell[wide];
        for (size_t j = 0; j < wide; j++) {
            this->cells[i][j] = reference_field.cells[i][j];
        }
    }
}

Field::Field(Field &&reference_field) : wide(reference_field.wide), height(reference_field.height) {

    reference_field.cells = nullptr;
    reference_field.height = -1;
    reference_field.wide = -1;
}

Field &Field::operator=(const Field &reference_field) {
    if (&reference_field == this) {
        return *this;
    }
    for (size_t i = 0; i < height; i++) {
        delete[] this->cells[i];
    }
    delete[] cells;

    this->wide = reference_field.wide;
    this->height = reference_field.height;
    for (size_t i = 0; i < height; i++) {
        for (size_t j = 0; j < wide; j++) {
            this->cells[i][j] = reference_field.cells[i][j]; /////////////////////tmp
        }
    }

    return *this;
}

Field &Field::operator=(Field &&reference_field) {
    if (&reference_field == this) {
        return *this;
    }

    for (size_t i = 0; i < height; i++) {
        delete[] this->cells[i];
    }
    delete[] cells;

    this->wide = reference_field.wide;
    this->height = reference_field.height;
    this->cells = reference_field.cells;
    reference_field.cells = nullptr;
    reference_field.height = -1;
    reference_field.wide = -1;

    return *this;
}

Field::~Field() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < wide; ++j) {
            if (cells[i][j].item_on_cell()) cells[i][j].remove_item();
        }
    }
    for (size_t i = 0; i < height; i++) {
        delete[] this->cells[i];
    }
    delete[] cells;
}

unsigned int Field::get_height() const {
    return this->height;
}

unsigned int Field::get_wide() const {
    return wide;
}

void Field::set_cells(Cell **cells) {
    if (cells) {
        for (size_t i = 0; i < height; i++) {
            delete[] this->cells[i];
        }
        delete[] cells;
        this->cells = cells;
    }
}

Cell &Field::get_cell(unsigned int x, unsigned int y) const {
    if (x < 0 || x > wide - 1 || y < 0 || y > height - 1) {
        throw "Coordinate error";
    }
    return cells[y][x];
}

bool Field::set_cell(unsigned int x, unsigned int y, Cell *cell) {
    if (x < 0 || y < 0 || x >= wide || y >= height) {
        return false;
    }
    if(cell){
        cells[y][x] = *cell;
        return true;
    }
    return false;
}

void Field::set_y_entrance_coordinate(unsigned int y) {
    entrance_coord = y;
}

void Field::set_y_exit_coordinate(unsigned int y) {
    exit_coord = y;
}

unsigned Field::get_entrance_coordinate()const {
    return entrance_coord;
}

unsigned Field::get_exit_coordinate() const{
    return exit_coord;
}

void Field::environment_exist_set() {
    environment_exist = true;
}

bool Field::is_environment_exist() const {
    return environment_exist;
}

void Field::set_height(unsigned int height) {
    this->height = height;
    if(wide != -1){
        cells = new Cell *[height];
        for (size_t i = 0; i < this->height; i++) {
            cells[i] = new Cell[wide];
        }
    }
}

void Field::set_wide(unsigned int wide) {
    this->wide = wide;
    if(height != -1){
        cells = new Cell *[height];
        for (size_t i = 0; i < this->height; i++) {
            cells[i] = new Cell[wide];
        }
    }
}

