//
// Created by igor on 11.11.2021.
//
#ifndef OOP_GAME_OBSERVER_H
#define OOP_GAME_OBSERVER_H

#include <string>
#include <fstream>
#include <vector>

class Player;
class Enemy;
class Subscriber;
class Observe_inf;

class Logger {
public:
    Logger();
    explicit Logger(const std::string& filename);
    ~Logger();

    static void sub_changes_to_out(std::vector<std::pair<Subscriber*, Observe_inf>>& information);
    static bool is_outf();
    static void message(const std::string& string);
    static void add_console_out();


private:
    static std::ofstream outf;
    static bool console_out;
    static bool file_out;


};


#endif