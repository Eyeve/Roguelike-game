//
// Created by eyeve on 03.09.2025.
//

#ifndef ROGUELIKE_GAME_TEXTUREMANAGER_H
#define ROGUELIKE_GAME_TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>

enum Textures
{
    Player,
    Ground,
    Wall,

    TextureCount
};

struct TextureManager {
public:
    TextureManager();

    int init();

    const sf::Texture& getTexture(Textures texture);

private:
    std::vector<sf::Texture> textureVec;
};


#endif //ROGUELIKE_GAME_TEXTUREMANAGER_H