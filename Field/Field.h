//
// Created by igor on 18.10.2021.
//


#pragma once




class Cell;
class Field {
public:
    Field()=default;

    Field(unsigned int wide, unsigned int height);

    ~Field();

    Field(const Field &reference_field);

    Field(Field &&reference_field);

    Field &operator=(const Field &reference_field);

    Field &operator=(Field &&reference_field);

    void set_cells(Cell **cells);

    unsigned int get_wide() const;

    unsigned int get_height() const;

    Cell &get_cell(unsigned int x, unsigned int y) const;

    bool set_cell(unsigned int x, unsigned int y, Cell *cell);

    void set_y_entrance_coordinate(unsigned);

    void set_y_exit_coordinate(unsigned);

    unsigned get_entrance_coordinate() const;

    unsigned get_exit_coordinate() const;

    void environment_exist_set();

    bool is_environment_exist() const;

    void set_wide(unsigned  wide);

    void set_height(unsigned height);

private:
    Cell **cells = nullptr;
    unsigned int wide = -1;
    unsigned int height = -1;
    bool environment_exist = false;
    unsigned entrance_coord = -1;
    unsigned exit_coord = -1;
};

//OOPGAME_FIELD_H
