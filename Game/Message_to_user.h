//
// Created by igor on 23.12.2021.
//
#pragma once

#include <string>

class Player;
class Message_to_user {
public:
    static void print_player_stats(Player& player);
    static void end();
    static void ask_player_for_save_num();
    static void ask_player_save_num();
    static void save_missing();
    static void ask_player_to_load_game();
    static void message(const std::string& string);
};

