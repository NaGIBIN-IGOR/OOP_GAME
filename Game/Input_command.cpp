#include <iostream>
#include "Input_command.h"
#include "Command_chars.h"


Command Input_command::command_from_input() {
    char input;
    std::cin >> input;
    Command com;
    if (commands_ready)
        com = command_chars.get_command(input);
    else
        com = CLOSE_GAME;
    return com;
}

void Input_command::set_command(Command com, std::string chars) {
    command_chars.set_command(com, chars);
    if (command_chars.is_commands()) {
        commands_ready = true;
    }

}

std::string Input_command::get_command(Command com) {
    return command_chars.get_command(com);
}



//void Input_command::set_left_move(std::string left) {
//    command_chars.set_left_move(left);
//}
//
//void Input_command::set_right_move(std::string right) {
//    command_chars.set_right_move(right);
//}
//
//void Input_command::set_up_move(std::string up) {
//    command_chars.set_up_move(up);
//}
//
//void Input_command::set_down_move(std::string down) {
//    command_chars.set_down_move(down);
//}
//
//void Input_command::set_close_game(std::string close) {
//    command_chars.set_close_game(close);
//}
