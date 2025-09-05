#include <iostream>
#include <utility>
#include <filesystem>
#include <string>

#include "Utility.h"
#include "TextureManager.h"


const std::map<std::string, TextureName> fileToTextureName{
                {"Basic",        TextureName::Basic},
                {"Troll",        TextureName::Troll},

                {"Ceil",         TextureName::Ceil},
                {"Down",         TextureName::Down},
                {"Floor",        TextureName::Floor},
                {"InDownLeft",   TextureName::InDownLeft},
                {"InDownRight",  TextureName::InDownRight},
                {"InUpLeft",     TextureName::InUpLeft},
                {"InUpRight",    TextureName::InUpRight},
                {"Left",         TextureName::Left},
                {"OutDownLeft",  TextureName::OutDownLeft},
                {"OutDownRight", TextureName::OutDownRight},
                {"OutUpLeft",    TextureName::OutUpLeft},
                {"OutUpRight",   TextureName::OutUpRight},
                {"Right",        TextureName::Right},
                {"Up",           TextureName::Up}
};

TextureManager::TextureManager(): textureVec(enumSize<TextureName>()) {

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
            TextureName name = fileToTextureName.at(fileName); // TODO: except
            if (!textureVec[std::to_underlying(name)].loadFromFile(filePath))
            {
                std::cerr << "Failed to load: " << filePath << '\n';
                return -1;
            }
        }
    }

    return 0;
}


const sf::Texture& TextureManager::getHandler(const TextureName name)
{
    return textureVec[std::to_underlying(name)];
}
