//
// Created by eyeve on 03.09.2025.
//

#ifndef ROGUELIKE_GAME_TEXTUREMANAGER_H
#define ROGUELIKE_GAME_TEXTUREMANAGER_H

#include <utility>
#include <SFML/Graphics.hpp>

enum class Textures
{
    Player,
    Ground,
    Wall,

    Size
};

template<typename T>
int enumSize() {
    return std::to_underlying(T::Size);
}

struct TextureManager {
public:
    TextureManager();

    int init();

    const sf::Texture& getTexture(Textures texture);

private:
    std::vector<sf::Texture> textureVec;
};


#endif //ROGUELIKE_GAME_TEXTUREMANAGER_H