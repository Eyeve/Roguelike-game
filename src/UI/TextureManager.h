//
// Created by eyeve on 03.09.2025.
//

#ifndef ROGUELIKE_GAME_TEXTUREMANAGER_H
#define ROGUELIKE_GAME_TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>

enum Textures
{
    player,
    ground,
    wall
};

struct TextureManager {
public:

    TextureManager();

    int init();

    static const sf::Texture* getTexture(Textures texture);
};


#endif //ROGUELIKE_GAME_TEXTUREMANAGER_H