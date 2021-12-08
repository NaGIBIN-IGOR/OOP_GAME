#include <iostream>

#include "Game.h"
#include "Logs/Watcher.h"
#include "Logs/Logger/Console_logger.h"
int main() {
    Game game;
    game.start();
    Console_logger c;
    c.add_file("file.txt");
}