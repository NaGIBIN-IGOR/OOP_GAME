//
// Created by igor on 08.11.2021.
//

#include "Textures.h"

sf::Sprite &Textures::get_sprite(char* path) {
    sf::Texture texture;
    texture.loadFromFile(path);

    sf::Sprite sprite;
    sprite.setTexture(texture);
    return  sprite;
}

sf::Sprite &Textures::wall_sprite() {
    return get_sprite(wall_pic_path);
}

sf::Sprite &Textures::hero_spite() {
    return get_sprite(hero_pic_path);
}

sf::Sprite &Textures::ogre_spite() {
    return get_sprite(ogre_enemy_pic_path);
}

sf::Sprite &Textures::knight_spite() {
    return get_sprite(knight_enemy_pic_path);
}

sf::Sprite &Textures::tiny_spite() {
    return get_sprite(tiny_enemy_pic_path);
}
