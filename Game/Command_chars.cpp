//
// Created by igor on 15.12.2021.
//
#include "Command_chars.h"

//Command Command_chars::get_command(char c) {
//    char single = toupper(c);
//    if(commands[MOVE_UP].find(single) != -1) return MOVE_UP;
//    else if(commands[MOVE_LEFT].find(single) != -1) return MOVE_LEFT;
//    else if(commands[MOVE_DOWN].find(single) != -1) return MOVE_DOWN;
//    else if(commands[MOVE_RIGHT].find(single) != -1) return MOVE_RIGHT;
//    else if (commands[CLOSE_GAME].find(single) != -1) return CLOSE_GAME;
//    else return UNDEF_COMMAND;
//}

Command Command_chars::get_command(char c) {
    char single = toupper(c);
    for(auto pair: commands){
        if(pair.second.find(single) != -1) return pair.first;
    }
    return UNDEF_COMMAND;
}

//void Command_chars::set_left_move(std::string left) {
//    for (int i = 0; i < left.size(); i++){
//        left[i] = toupper(left[i]);
//    }
//    commands[MOVE_LEFT] = left;
//}
//
//void Command_chars::set_right_move(std::string right) {
//    for (int i = 0; i < right.size(); i++){
//        right[i] = toupper(right[i]);
//    }
//    commands[MOVE_RIGHT] = right;
//}
//
//void Command_chars::set_up_move(std::string up) {
//    for (int i = 0; i < up.size(); i++){
//        up[i] = toupper(up[i]);
//    }
//    commands[MOVE_UP] = up;
//}
//
//void Command_chars::set_down_move(std::string down) {
//    for (int i = 0; i < down.size(); i++){
//        down[i] = toupper(down[i]);
//    }
//    commands[MOVE_DOWN] = down;
//}
//
//void Command_chars::set_close_game(std::string close) {
//    for (int i = 0; i < close.size(); i++){
//        close[i] = toupper(close[i]);
//    }
//    commands[CLOSE_GAME] = close;
//}

bool Command_chars::is_commands() {
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
    bool close = false;
    bool undef_com = true;
    for(const auto& pair: commands){
        switch (pair.first){
            case MOVE_UP:
                if(!pair.second.empty()) up = true;
                break;
            case MOVE_DOWN:
                if(!pair.second.empty()) down = true;
                break;
            case MOVE_LEFT:
                if(!pair.second.empty()) left = true;
                break;
            case MOVE_RIGHT:
                if(!pair.second.empty()) right = true;
                break;
            case CLOSE_GAME:
                if(!pair.second.empty()) close = true;
                break;
            case UNDEF_COMMAND:
                undef_com = false;
                break;
        }
    }
    if(up && down && left && right && close && undef_com) return true;
    return false;
}


void Command_chars::set_command(Command com, std::string chars) {
    for (int i = 0; i < chars.size(); i++){
        chars[i] = toupper(chars[i]);
    }
    commands.push_back(std::pair(com, chars));
}

std::string Command_chars::get_command(Command com) {
    for(auto elem: commands){
        if(elem.first == com) return elem.second;
    }
    return "";
}


