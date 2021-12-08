//
// Created by igor on 29.11.2021.
//

#pragma once

#include <string>
#include <vector>

#include "../Watcher.h"
#include "../../On_cell_objects/Subscriber.h"

class Logger {
public:
    Logger();
    virtual ~Logger();
    virtual void message(std::string message);
    void add_console();
    void add_file(const std::string& filename);
    void add_logger_object(Subscriber* subscriber);
    void remove_dead_logger_objects();
    void write_change_objects();
private:
    std::vector<Logger*> loggers;
    Watcher watcher;
    bool console_out = false;

};


