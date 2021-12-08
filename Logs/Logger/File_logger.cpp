//
// Created by igor on 29.11.2021.
//

#include "File_logger.h"

File_logger::File_logger(std::string filename) {
    remove(filename.c_str());
    outf.open(filename, std::ios::app);
}

File_logger::~File_logger() {
    std::cout << "File has been closed\n";
    outf.close();
}

void File_logger::message(std::string string) {
    outf<<string;
}

bool File_logger::is_open() {
    return outf.is_open();
}
