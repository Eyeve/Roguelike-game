//
// Created by eyeve on 03.09.2025.
//

#include "TextureManager.h"
#include <iostream>
#include <magic_enum.hpp>
#include <utility>
#include <filesystem>
#include <string>

const std::map<std::string, Texture> fileNameToTextureEnum{
                {"Basic",        Texture::Basic},
                {"Troll",        Texture::Troll},

                {"Ceil",         Texture::Ceil},
                {"Down",         Texture::Down},
                {"Floor",        Texture::Floor},
                {"InDownLeft",   Texture::InDownLeft},
                {"InDownRight",  Texture::InDownRight},
                {"InUpLeft",     Texture::InUpLeft},
                {"InUpRight",    Texture::InUpRight},
                {"Left",         Texture::Left},
                {"OutDownLeft",  Texture::OutDownLeft},
                {"OutDownRight", Texture::OutDownRight},
                {"OutUpLeft",    Texture::OutUpLeft},
                {"OutUpRight",   Texture::OutUpRight},
                {"Right",        Texture::Right},
                {"Up",           Texture::Up}
};
TextureManager::TextureManager(): textureVec(enumSize<Texture>()) {

}


int TextureManager::init()
{

    const std::filesystem::path root = "../assets";

    if (!std::filesystem::exists(root)) {
        std::cerr << "Folder is not found " << root << '\n';
        return 1;
    }

    for (const auto& entry :
         std::filesystem::recursive_directory_iterator(root,
                                          std::filesystem::directory_options::skip_permission_denied))
    {
        if (entry.is_regular_file()) {
            std::string filePath = entry.path().string();
            std::string fileName = entry.path().stem().string();
            Texture texture = fileNameToTextureEnum.at(fileName); // TODO: except
            if (!textureVec[std::to_underlying(texture)].loadFromFile(filePath))
            {
                std::cerr << "Failed to load: " << filePath << '\n';
                return -1;
            }
        }
    }

    return 0;
}


const sf::Texture& TextureManager::getTexture(const Texture texture)
{
    return textureVec[std::to_underlying(texture)];
}
