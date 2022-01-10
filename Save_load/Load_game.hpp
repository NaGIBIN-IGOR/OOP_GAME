//
// Created by igor on 23.12.2021.
//

#pragma once

#include <fstream>
#include <string>
#include "Game_save.h"


class Load_game {
public:
    Load_game() = default;

     Game_save* load_game(unsigned save_number, std::string save_dir = "../Save_load/Saves/");

private:
    std::string file_correct_check(unsigned save_number, std::string save_dir);

};
