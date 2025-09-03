//
// Created by eyeve on 03.09.2025.
//

#ifndef ROGUELIKE_GAME_TEXTUREMANAGER_H
#define ROGUELIKE_GAME_TEXTUREMANAGER_H

#include <utility>
#include <SFML/Graphics.hpp>
#include <string>
enum class Textures
{
    Wall,
    Troll
};

template<typename T>
int enumSize() {
    return std::to_underlying(T::Size);
}

struct TextureManager {
public:
    TextureManager();

    int init();

    const sf::Texture& getTexture(const std::string& texture);

private:
    std::map<std::string, sf::Texture> textureMap;
};


#endif //ROGUELIKE_GAME_TEXTUREMANAGER_H