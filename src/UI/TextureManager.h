//
// Created by eyeve on 03.09.2025.
//

#ifndef ROGUELIKE_GAME_TEXTUREMANAGER_H
#define ROGUELIKE_GAME_TEXTUREMANAGER_H

#include <utility>
#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>

enum class Texture {
    Basic,
    Troll,

    Ceil,
    Down,
    Floor,
    InDownLeft,
    InDownRight,
    InUpLeft,
    InUpRight,
    Left,
    OutDownLeft,
    OutDownRight,
    OutUpLeft,
    OutUpRight,
    Right,
    Up,

    _Size
};

template<typename T>
int enumSize() {
    return std::to_underlying(T::_Size);
}

struct TextureManager {
public:
    TextureManager();

    int init();

    const sf::Texture& getTexture(const Texture texture);

private:
    std::vector<sf::Texture> textureVec;
};


#endif //ROGUELIKE_GAME_TEXTUREMANAGER_H