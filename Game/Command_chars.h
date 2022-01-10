//
// Created by igor on 15.12.2021.
//
#pragma once
#include "../Enums/Command.h"
#include <vector>
#include <string>

class Command_chars {
public:
    Command_chars()=default;
    Command get_command(char c);
    std::string get_command(Command com);
    void set_command(Command com, std::string chars);
    bool is_commands();
private:
    std::vector<std::pair<Command, std::string>> commands;
};
//    void set_left_move(std::string left);
//    void set_right_move(std::string right);
//    void set_up_move(std::string up);
//    void set_down_move(std::string down);
//    void set_close_game(std::string close);