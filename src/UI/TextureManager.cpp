//
// Created by eyeve on 03.09.2025.
//

#include "TextureManager.h"

TextureManager::TextureManager(): textureVec(TextureCount, sf::Texture()) {

}


int TextureManager::init()
{
    for (int i = 0; i < TextureCount; ++i) {
        if (textureVec[i].loadFromFile("../assets/player.png"))
            return -1;
    }
    return 0;
}


const sf::Texture& TextureManager::getTexture(Textures texture)
{
    return textureVec[texture];
}
