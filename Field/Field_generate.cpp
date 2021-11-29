//
// Created by igor on 18.10.2021.
//

#include <iostream>

#include "Field_generate.h"
#include "../On_cell_objects/Items/Max_health_damage_increase.h"
#include "../On_cell_objects/Items/Heal_item.h"
#include "../On_cell_objects/Items/Damage_increase_item.h"
#include "../On_cell_objects/Enemies/Knight_enemy.h"
#include "../On_cell_objects/Enemies/Tiny_enemy.h"
#include "../On_cell_objects/Enemies/Ogre_enemy.h"
#include "../Cell/Cell_entrance.h"
#include "../Cell/Cell_exit.h"
#include "../On_cell_objects/Enemies/Enemy_controller.h"

#define ITEMS_NUMBER 3
#define ENEMIES_NUMBER 3



bool Field_generate::environment_generate(Field& field) {
    if (field.is_environment_exist()) return false;
    if(field.get_wide() <= 3 || field.get_height() <= 3) return true;
    wall_generate(field);
    floor_generate(field);
    enter_exit_generate(field);
    field.environment_exist_set();
    return false;
}

void Field_generate::enter_exit_generate(Field& field) {
    if (field.get_wide() == 0) return;
    std::srand(time(nullptr));

    unsigned int ent_x_coordinate = 0;
    unsigned int ent_y_coordinate = y_rand_coord_generate(field);

    Cell *ent_random_cell = new Cell_entrance();
    field.set_cell(ent_x_coordinate, ent_y_coordinate, ent_random_cell);
    delete ent_random_cell;
    field.set_y_entrance_coordinate(ent_y_coordinate);

    unsigned int exit_x_coordinate = field.get_wide() - 1;
    unsigned int exit_y_coordinate = y_rand_coord_generate(field);

    Cell *exit_random_cell = new Cell_exit();
    field.set_cell(exit_x_coordinate, exit_y_coordinate, exit_random_cell);
    delete exit_random_cell;
    field.set_y_exit_coordinate(exit_y_coordinate);
}

void Field_generate::floor_generate(Field& field) {
    if (field.get_wide() == 0) return;
    for (size_t height = 1; height < field.get_height() - 1; height++) {
        for (size_t width = 1; width < field.get_wide() - 1; width++) {

            Cell &cell = field.get_cell(width, height);
            cell.set_cell_type_inf(PASSABLE_CELL);
            cell.set_passable(true);
        }

    }

}

void Field_generate::wall_generate(Field& field) {
    if (field.get_wide() == 0) return;
    for (size_t width = 0; width < field.get_wide(); width++) {
        Cell &cell = field.get_cell(width, 0);
        cell.set_passable(false);
        cell.set_cell_type_inf(WALL);
    }
    for (size_t height = 1; height < field.get_height(); height++) {
        Cell &cell = field.get_cell(field.get_wide() - 1, height);
        cell.set_passable(false);
        cell.set_cell_type_inf(WALL);
    }

    for (size_t width = 0; width < field.get_wide() - 1; width++) {
        Cell &cell = field.get_cell(width, field.get_height() - 1);
        cell.set_passable(false);
        cell.set_cell_type_inf(WALL);
    }
    for (size_t height = 1; height < field.get_height() - 1; height++) {
        Cell &cell = field.get_cell(0, height);
        cell.set_passable(false);
        cell.set_cell_type_inf(WALL);
    }

}

Item* Field_generate::add_rand_item(Field& field) {
    if (!field.is_environment_exist()) return nullptr;

    unsigned rand_x_coord = x_rand_coord_generate(field);
    unsigned rand_y_coord = y_rand_coord_generate(field);

    unsigned rand_item_choice = rand() % ITEMS_NUMBER;
    Item* it = nullptr;

    if(!field.get_cell(rand_x_coord, rand_y_coord).item_on_cell()
    && !field.get_cell(rand_x_coord, rand_y_coord).player_on_cell()
    && !field.get_cell(rand_x_coord, rand_y_coord).enemy_on_cell()) {

        switch (rand_item_choice) {
            case 0:
                it = new Heal_item;
                field.get_cell(rand_x_coord, rand_y_coord).set_item(it);
                break;
            case 1:
                it = new Damage_increase_item;
                field.get_cell(rand_x_coord, rand_y_coord).set_item(it);
                break;
            case 2:
                it = new Max_health_damage_increase;
                field.get_cell(rand_x_coord, rand_y_coord).set_item(it);
                break;
        }
    }
    return it;
}

unsigned int Field_generate::x_rand_coord_generate(Field& field) {
    unsigned rand_x_coord = rand() % field.get_wide();
    if (rand_x_coord == field.get_wide() - 1) --rand_x_coord;
    if (rand_x_coord == 0) ++rand_x_coord;
    return rand_x_coord;
}

unsigned int Field_generate::y_rand_coord_generate(Field& field) {
    unsigned rand_y_coord = rand() % field.get_height();
    if (rand_y_coord == field.get_height() - 1) --rand_y_coord;
    if (rand_y_coord == 0) ++rand_y_coord;
    return rand_y_coord;
}

Enemy* Field_generate::add_rand_enemy(Field& field) {
    if(!field.is_environment_exist()) return nullptr;
    unsigned rand_x_coord = x_rand_coord_generate(field);
    unsigned rand_y_coord = y_rand_coord_generate(field);
    unsigned choice = rand() % ENEMIES_NUMBER;

    Enemy* enemy = nullptr;

    if(!field.get_cell(rand_x_coord, rand_y_coord).item_on_cell()
       && !field.get_cell(rand_x_coord, rand_y_coord).player_on_cell()
       && !field.get_cell(rand_x_coord, rand_y_coord).enemy_on_cell()) {
        switch (choice) {
            case 0:
                enemy = new Tiny_enemy(rand_x_coord, rand_y_coord);
                field.get_cell(rand_x_coord, rand_y_coord).set_enemy(enemy);
                break;
            case 1:
                enemy = new Knight_enemy(rand_x_coord, rand_y_coord);
                field.get_cell(rand_x_coord, rand_y_coord).set_enemy(enemy);
                break;
            case 2:
                enemy = new Ogre_enemy(rand_x_coord, rand_y_coord);
                field.get_cell(rand_x_coord, rand_y_coord).set_enemy(enemy);
                break;
        }
        return enemy;
    }
}
