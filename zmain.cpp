#include <iostream>

#include "Game/Game.h"
#include "Game/Game.cpp"
#include "Conditions/Lose_condition.h"
#include "Conditions/Win_condition_exit.h"
#include "Conditions/Win_condition_items.h"
#include "Save_load/Game_loader.h"
#include "Game/Message_to_user.h"

int main() {
    const unsigned difficulty = 1;
    Game<Win_condition_exit<difficulty>, Lose_condition<difficulty>> game(difficulty);
    Game_save* save = game.prepare_start();
    if(save) {
        Game_loader loader(save);
        loader.start_load_game();
    }
    return 0;
}