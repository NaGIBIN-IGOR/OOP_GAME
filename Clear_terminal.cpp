//
// Created by igor on 26.10.2021.
//
#include <typeinfo>
#include <termios.h>
#include <unistd.h>
#include <iostream>
#include "Clear_terminal.h"
void Clear_terminal::clear_terminal_icanon()
{
    static struct termios told, tnew;
    tcgetattr(STDIN_FILENO, &told);
    tnew = told;
    tnew.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &tnew);
}

void Clear_terminal::set_terminal_icanon()
{
    static struct termios told, tnew;
    tcgetattr(STDIN_FILENO, &told);
    tnew = told;
    tnew.c_lflag |= ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &tnew);
}


void Clear_terminal::clear_screen()
{
    std::cout << "\033[H\033[J";
}