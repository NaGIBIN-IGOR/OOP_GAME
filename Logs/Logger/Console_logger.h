//
// Created by igor on 29.11.2021.
//

#pragma once

#include "Logger.h"

class Console_logger: public Logger {
public:
    Console_logger();
    void message(std::string message) override;
};