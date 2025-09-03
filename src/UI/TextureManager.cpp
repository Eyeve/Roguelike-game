//
// Created by eyeve on 03.09.2025.
//

#include "TextureManager.h"
#include <iostream>
#include <magic_enum.hpp>
#include <utility>

TextureManager::TextureManager(): textureVec(magic_enum::enum_values<Textures>().size(), sf::Texture()) {

}


int TextureManager::init()
{

    for (Textures t : magic_enum::enum_values<Textures>()) {
        auto idx_opt = magic_enum::enum_index(t);
        if (!idx_opt)
            continue;

        std::size_t idx = *idx_opt;
        std::string path = "../assets/" + std::string(magic_enum::enum_name(t)) + ".png";

        if (!textureVec[idx].loadFromFile(path)) {
            std::cerr << "Failed to load: " << path << '\n';
            return -1;
        }
    }
    return 0;
}


const sf::Texture& TextureManager::getTexture(Textures texture)
{
    return textureVec[std::to_underlying(texture)];
}
