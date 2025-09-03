//
// Created by eyeve on 03.09.2025.
//

#include "TextureManager.h"
#include <iostream>
#include <magic_enum.hpp>
#include <utility>
#include <filesystem>
#include <string>

const std::map<std::string, Textures> fileNameToTextureEnum{
                {"Basic",        Textures::Basic},
                {"Troll",        Textures::Troll},

                {"Ceil",         Textures::Ceil},
                {"Down",         Textures::Down},
                {"Floor",        Textures::Floor},
                {"InDownLeft",   Textures::InDownLeft},
                {"InDownRight",  Textures::InDownRight},
                {"InUpLeft",     Textures::InUpLeft},
                {"InUpRight",    Textures::InUpRight},
                {"Left",         Textures::Left},
                {"OutDownLeft",  Textures::OutDownLeft},
                {"OutDownRight", Textures::OutDownRight},
                {"OutUpLeft",    Textures::OutUpLeft},
                {"OutUpRight",   Textures::OutUpRight},
                {"Right",        Textures::Right},
                {"Up",           Textures::Up}
};
TextureManager::TextureManager() {

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
            Textures texture = fileNameToTextureEnum.at(fileName);
            textureMap[texture] = sf::Texture();
            if (!textureMap[texture].loadFromFile(filePath))
            {
                std::cerr << "Failed to load: " << filePath << '\n';
                return -1;
            }
        }
    }

    return 0;
}


const sf::Texture& TextureManager::getTexture(const Textures texture)
{
    return textureMap[texture];
}
