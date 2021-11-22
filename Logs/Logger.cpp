//
// Created by igor on 11.11.2021.
//

#include <iostream>
#include <sstream>
#include "Logger.h"
#include "Observe_inf.h"
#include "Observer.h"

#include "../On_cell_objects/Subscriber.h"

std::ofstream Logger::outf;
bool Logger::console_out = false;
bool Logger::file_out = false;

Logger::Logger() {
    console_out = true;
}

Logger::~Logger() {
    file_out = false;
    console_out = false;
    outf.close();
}

Logger::Logger(const std::string& filename){
    remove(filename.c_str());
    outf.open(filename, std::ios::app);
    if(outf.is_open())file_out = true;
}

void Logger::add_console_out() {
    console_out = true;
}

void Logger::message(const std::string& string) {
    if(console_out)std::cout<<string;
    if(file_out)outf << string;
}


bool Logger::is_outf() {
    return outf.is_open();
}

void Logger::sub_changes_to_out(std::vector<std::pair<Subscriber *, Observe_inf>> &information) {
    for(auto elem: information){
        auto& sub = *elem.first;
        auto inf = elem.second;
        if(inf.health_change || inf.damage_change || inf.x_coordinate_change || inf.y_coordinate_change){
            std::stringstream ss;
            ss<<sub;
            if(inf.health_change) ss << " Здоровье изменено;";
            if(inf.damage_change) ss << " Урон изменён;";
            if(inf.x_coordinate_change || inf.y_coordinate_change) ss << " Перешёл на другую клетку;";

            ss<<"\n";
            message(ss.str());
        }
    }

}