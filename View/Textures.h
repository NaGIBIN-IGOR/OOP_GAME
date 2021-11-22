//
// Created by igor on 08.11.2021.
//

#ifndef OOP_GAME_TEXTURES_H
#define OOP_GAME_TEXTURES_H
#include <SFML/Graphics.hpp>
////////////////////////////////   cmakefile: ./View/Textures.cpp ./View/Textures.h
class Textures {
public:
    sf::Sprite& wall_sprite();
    sf::Sprite& hero_spite();
    sf::Sprite& ogre_spite();
    sf::Sprite& knight_spite();
    sf::Sprite& tiny_spite();

    sf::Sprite& get_sprite(char* path);
private:
    char* wall_pic_path = "./Texture_source/wall.png";
    char* hero_pic_path = "";
    char* ogre_enemy_pic_path = "";
    char* knight_enemy_pic_path = "";
    char* tiny_enemy_pic_path = "";
};


#endif //OOP_GAME_TEXTURES_H
