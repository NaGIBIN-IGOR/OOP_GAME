//
// Created by igor on 08.12.2021.
//

#pragma once
#include "../Game/Game_inf.h"
#include "../On_cell_objects/Player.h"
#include "../Game/Game_inf.h"
#include "../Field/Field.h"

class Player; class Field;

class Condition{
public:
    virtual bool is_met(Player &player, Game_inf &game_inf, Field &field) const = 0;
private:

};
