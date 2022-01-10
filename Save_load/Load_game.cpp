//
// Created by igor on 04.01.2022.
//
#include "Load_game.hpp"
#include "Json_description.hpp"
#include "Json_to_data.hpp"

Game_save* Load_game::load_game(unsigned int save_number, std::string save_dir) {
    if (save_number >= 1 && save_number < 5) {
        std::string json_f;
        try {
            json_f = file_correct_check(save_number, save_dir);
        }
        catch (const char* ex){
            throw ex;
        }
        nlohmann::json json = nlohmann::json::parse(json_f);
        Json_to_data json_data;
        Game_save* game_save =  json_data.get_game(json);

        return game_save;
    }
}

std::string Load_game::file_correct_check(unsigned save_number, std::string save_dir) {
    std::fstream save_file;
    auto save_file_path = save_dir + "Save" + std::to_string(save_number) + ".json";
    save_file.open(save_file_path);
    if (save_file.is_open()) {
        std::fstream hash_file;
        auto hash_file_path = save_dir + "Hash" + std::to_string(save_number) + ".txt";
        hash_file.open(hash_file_path);
        if (hash_file.is_open()) {
            std::string inside_file;
            std::string tmp;
            while (getline(save_file, tmp, '\n')) {
                inside_file += tmp;
                tmp = "";
            }
            std::string str_hash;
            getline(hash_file, str_hash);
            std::string file_hash = std::to_string(std::hash<std::string>{}(inside_file));
            if (str_hash == file_hash) {
                return inside_file;
            } else throw "Сохранение некорректно";
        }
        else throw "Хэш сохранения не найдено";
    }
    else throw "Сохранение не найдено";
}

