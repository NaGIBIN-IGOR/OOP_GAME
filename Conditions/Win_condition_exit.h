//
// Created by igor on 08.12.2021.
//

#pragma once
#include "Condition.h"
#include "Win_condition.h"

template<unsigned difficulty>
class Win_condition_exit : public Win_condition{
public:
    bool is_met(Player &player, Game_inf &game_inf, Field &field) const override;
};

template<unsigned int difficulty>
bool Win_condition_exit<difficulty>::is_met(Player &player, Game_inf &game_inf, Field &field)const {
    if(game_inf.turn_number >= difficulty*7)
        return true;
    else return false;
}


