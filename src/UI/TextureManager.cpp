//
// Created by eyeve on 03.09.2025.
//

#include "TextureManager.h"

#include <utility>

TextureManager::TextureManager(): textureVec(enumSize<Textures>(), sf::Texture()) {

}


int TextureManager::init()
{
    for (int i = 0; i < enumSize<Textures>(); ++i) {
        if (textureVec[i].loadFromFile("../assets/wall.png"))
            return -1;
    }
    return 0;
}


const sf::Texture& TextureManager::getTexture(Textures texture)
{
    return textureVec[std::to_underlying(texture)];
}
