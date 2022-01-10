#pragma once

#include "../Game/Game_inf.h"
#include "../Game/Game_control_inf.h"
#include "../Game/Command_chars.h"
#include "../On_cell_objects/Player.h"
#include <vector>
#include <string>
class Field;
struct Game_save{
    unsigned difficulty;
    Field* field;
    Player* player;
    Game_inf game_inf;
    Game_control_inf control_inf;
    std::vector<std::pair<Command, std::string>> input_commands;
    std::vector<Enemy*> enemies;
    std::string win_rule;

};