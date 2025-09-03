//
// Created by eyeve on 03.09.2025.
//

#include "TextureManager.h"
#include <iostream>
#include <magic_enum.hpp>
#include <utility>
#include <filesystem>
#include <string>

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
            textureMap[entry.path().stem().string()] = sf::Texture();
            if (!textureMap[entry.path().stem().string()].loadFromFile(filePath))
            {
                std::cerr << "Failed to load: " << filePath << '\n';
                return -1;
            }
        }
    }

    return 0;
}


const sf::Texture& TextureManager::getTexture(const std::string& texture)
{
    return textureMap[texture];
}
