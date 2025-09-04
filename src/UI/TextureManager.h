#ifndef ROGUELIKE_GAME_TEXTUREMANAGER_H
#define ROGUELIKE_GAME_TEXTUREMANAGER_H

#include <utility>
#include <SFML/Graphics.hpp>

enum class TextureName {
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

    None
};

template<typename T>
int enumSize() {
    return std::to_underlying(T::None);
}

struct TextureManager {
public:
    TextureManager();

    int init();

    const sf::Texture& getTexture(TextureName texture);

private:
    std::vector<sf::Texture> textureVec;
};


#endif