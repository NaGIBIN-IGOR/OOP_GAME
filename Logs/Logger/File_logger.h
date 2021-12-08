//
// Created by igor on 29.11.2021.
//

#ifndef OOP_GAME_FILE_LOGGER_H
#define OOP_GAME_FILE_LOGGER_H

#include "Logger.h"
#include "fstream"

class File_logger: public Logger{
public:
    explicit File_logger(std::string filename);
    ~File_logger();
    void message(std::string string) override;
    bool is_open();
private:
    std::ofstream outf;
};


#endif //OOP_GAME_FILE_LOGGER_H
