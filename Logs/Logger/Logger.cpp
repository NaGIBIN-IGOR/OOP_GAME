//
// Created by igor on 29.11.2021.
//
#include <sstream>

#include "Logger.h"
#include "Console_logger.h"
#include "File_logger.h"
#include <typeinfo>

Logger::Logger() =default;

Logger::~Logger() {
    for(Logger* log: loggers){
        delete log;
    }
}

void Logger::add_console() {
    if(!console_out) loggers.push_back(new Console_logger());
    console_out = true;

}

void Logger::add_file(const std::string &filename) {
    auto* out = new File_logger(filename);
    if(out->is_open()){
        loggers.push_back(out);
    }
    else delete out;
}

void Logger::message(std::string message) {
    for(auto* log: loggers){
        log->message(message);
    }
}

void Logger::add_logger_object(Subscriber *subscriber) {
    watcher.add_observer(subscriber);
}


void Logger::remove_dead_logger_objects() {
    watcher.remove_dead_subs();
}

void Logger::write_change_objects() {
    std::vector<std::pair<Subscriber *, Observe_inf*>>* information = watcher.check_subscribers();
    if(information == nullptr) return;
    message("\n");
    for (auto elem: *information) {
        auto &sub = *elem.first;
        auto &inf = *elem.second;
        std::stringstream ss;
        ss << '\t' << sub << ":";

        if (inf.health_change) ss << " Здоровье изменено;";
        if (inf.damage_change) ss << " Урон изменён;";
        if (inf.x_coordinate_change || inf.y_coordinate_change) {
            ss << " Перешёл на другую клетку;";
            ss << "\n";
            ss << "\t\t" << "Координаты: " << sub.get_x_coordinate() << ' ' << sub.get_y_coordinate() << std::endl;
        }
        if (!inf.y_coordinate_change && !inf.x_coordinate_change) ss << '\n';
        if (inf.health_change || inf.damage_change)
            ss << '\t' << '\t' << sub.get_health() << " hp " << sub.get_damage() << " dmg\n";
        ss << '\n';

        message(ss.str());
    }
    for(auto elem: *information){
        delete elem.second;
    }
    delete information;
}
