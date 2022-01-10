//
// Created by igor on 20.12.2021.
//

#pragma once

#include "../Game/Game.h"
#include "Json_description.hpp"
#include <fstream>
#include "../Game/Message_to_user.h"

class Save_game {
public:
    Save_game() = default;

    template<typename win_rule, typename lose_rule>
    void save_game(Game<win_rule, lose_rule> &game, unsigned save_number, std::string save_dir = "../Save_load/Saves/");
};

template<typename win_rule, typename lose_rule>
void Save_game::save_game(Game<win_rule, lose_rule> &game, unsigned save_number, std::string save_dir) {
    Json_description json_description;
    nlohmann::json json = json_description.to_json(game);
    std::string debug = json.dump();
    if (save_number >= 1 && save_number < 5) {
        std::fstream f;
        std::string savefname = save_dir + "Save" + std::to_string(save_number) + ".json";
        remove(savefname.c_str());
        f.open(savefname, std::ios::app);
        if (f.is_open()) {
            f << std::setw(4) << json;
            f.close();
            std::string hashfname = save_dir + "Hash" + std::to_string(save_number) + ".txt";
            std::fstream fhash;
            fhash.open(hashfname, std::fstream::out);

            std::fstream vsave;
            vsave.open(savefname);
            if (fhash.is_open() && vsave.is_open()) {
                std::string inside_file;
                std::string tmp;
                while (getline(vsave, tmp, '\n')) {
                    inside_file += tmp;
                    tmp = "";
                }
                auto hash = std::hash<std::string>{}(inside_file);
                fhash << hash;
                fhash.close();
            }
            else{
                remove(savefname.c_str());
                std::cout<< "Некорректное сохранение\n";
            }
        }
        else std::cout << "Игра не сохранена\n";

    }
    else Message_to_user::save_missing();
}

