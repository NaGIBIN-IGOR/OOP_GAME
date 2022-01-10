//
// Created by igor on 08.12.2021.
//

#pragma once
#include "Condition.h"


template<unsigned difficulty>
class Lose_condition: public Condition{
public:
    bool is_met(Player &player, Game_inf &game_inf, Field &field) const override;

};

template<unsigned difficulty>
bool Lose_condition<difficulty>::is_met(Player &player, Game_inf &game_inf, Field &field) const{
    if((player.get_health()/(difficulty+1) <= 5 && game_inf.dead_enemy_number < difficulty+1)){
        return true;
    }
    else return false;
}
