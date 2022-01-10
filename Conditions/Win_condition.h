//
// Created by igor on 08.12.2021.
//
#pragma once
#include "Condition.h"
class Win_condition: public Condition{
public:
    bool is_met(Player &player, Game_inf &game_inf, Field &field)const = 0;
};