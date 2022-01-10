//
// Created by igor on 23.12.2021.
//

#include "Message_to_user.h"
#include "../On_cell_objects/Player.h"
#include <iostream>

void Message_to_user::ask_player_for_save_num() {
    std::cout << "В какое сохранение записать текущую игру?" << '\n';

}

void Message_to_user::print_player_stats(Player &player) {
    std::cout<<player<<' '<< player.get_health() << " hp " << player.get_damage() << " dmg\n";

}

void Message_to_user::end() {
    std::cout<<"\t\tTHE END\t\t\n";
}

void Message_to_user::ask_player_save_num() {
    std::cout << "Открыть сохранение под номером(1-5): ";

}

void Message_to_user::save_missing() {
    std::cout << "Сохранение не найдено" << '\n';
}

void Message_to_user::ask_player_to_load_game() {
    std::cout << "Загрузить игру?\n1. Да\n2. Нет\n";
}

void Message_to_user::message(const std::string &string) {
    std::cout<<string;
}

