//
// Created by eyeve on 03.09.2025.
//

#ifndef ROGUELIKE_GAME_TEXTUREMANAGER_H
#define ROGUELIKE_GAME_TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>


struct TextureManager {
public:
    sf::Texture player;


    TextureManager();

    int init();
};


#endif //ROGUELIKE_GAME_TEXTUREMANAGER_H