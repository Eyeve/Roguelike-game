#ifndef ROGUELIKE_GAME_TEXTURE_MANAGER_H
#define ROGUELIKE_GAME_TEXTURE_MANAGER_H


#include <SFML/Graphics.hpp>

#include "ManagerInterface.h"

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

class TextureManager: public ManagerInterface<TextureName, sf::Texture> {
public:
    TextureManager();

protected:
    int init() override;
    const sf::Texture& getHandler(TextureName name) override;

private:
    std::vector<sf::Texture> textureVec;
};

#endif
