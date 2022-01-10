//
// Created by igor on 14.12.2021.
//

#pragma once

#include "Command_chars.h"

class Input_command {
public:
    Command command_from_input();
    void set_command(Command com, std::string chars);
    std::string get_command(Command com);
private:
    bool commands_ready = false;
    Command_chars command_chars;
};
