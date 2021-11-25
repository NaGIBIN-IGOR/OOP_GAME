//
// Created by igor on 11.11.2021.
//
#pragma once

#include <string>
#include <fstream>
#include <vector>

#include "Observer.h"
#include "Observe_inf.h"
#include "../On_cell_objects/Player.h"
#include "../On_cell_objects/Enemies/Enemy.h"
#include "../On_cell_objects/Subscriber.h"


class Logger {
public:
    explicit Logger(const std::string& filename);
    ~Logger();

    static bool is_outf();
    static void message(const std::string& string);
    static void add_console_out();
    static void sub_changes_to_out(std::vector<std::pair<Subscriber*, Observe_inf>>& information);
    void add_observed(Subscriber* subscriber);
    void check_dead_observed();
    void check_subs();

private:
    Observer obs;
    static std::ofstream outf;
    static bool console_out;
    static bool file_out;

};


