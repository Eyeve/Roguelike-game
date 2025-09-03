//
// Created by eyeve on 03.09.2025.
//

#include "TextureManager.h"

TextureManager::TextureManager()
= default;


int TextureManager::init()
{
    return 0;
}


const sf::Texture* TextureManager::getTexture(const Textures texture)
{
    auto* texturePtr = new sf::Texture();
    texturePtr->loadFromFile("../assets/" + std::to_string(texture));
    return texturePtr;
}
