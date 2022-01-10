//
// Created by igor on 08.12.2021.
//
#pragma once
#include "Win_condition.h"

template<unsigned difficulty>
class Win_condition_items : public Win_condition{
public:
    Win_condition_items()=default;
    bool is_met(Player &player, Game_inf &game_inf, Field &field) const override;
};

template<unsigned int difficulty>
bool Win_condition_items<difficulty>::is_met(Player &player, Game_inf &game_inf, Field &field) const{
    if(game_inf.picked_up_item_number > 3*difficulty)
        return true;
    else return false;
}
