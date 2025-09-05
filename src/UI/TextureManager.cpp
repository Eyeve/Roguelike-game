#include <iostream>
#include <utility>
#include <filesystem>
#include <string>
#include <unordered_map>


#include "Utility.h"
#include "TileManager.h"
#include "TextureManager.h"


TextureManager::TextureManager(): textures(enumSize<TextureType>()) {

}

int TextureManager::init()
{
    static std::unordered_map<std::string, TileType> tileset = {
        {"Ceil",         TileType::Ceil},
        {"Down",         TileType::Down},
        {"Floor",        TileType::Floor},
        {"InDownLeft",   TileType::InDownLeft},
        {"InDownRight",  TileType::InDownRight},
        {"InUpLeft",     TileType::InUpLeft},
        {"InUpRight",    TileType::InUpRight},
        {"Left",         TileType::Left},
        {"OutDownLeft",  TileType::OutDownLeft},
        {"OutDownRight", TileType::OutDownRight},
        {"OutUpLeft",    TileType::OutUpLeft},
        {"OutUpRight",   TileType::OutUpRight},
        {"Right",        TileType::Right},
        {"Up",           TileType::Up},
    };

    if (textureSearch<TileType>("tileset", TextureType::Tileset, tileset))
        return -1;

    return 0;
}


const sf::Texture& TextureManager::getHandler(const TextureKey name)
{
    return textures[name.type][name.id];
}

template<typename T>
int TextureManager::textureSearch(const std::string& directory, TextureType type, const std::unordered_map<std::string, T>& map) {
    std::vector<sf::Texture>& ref = textures[std::to_underlying(type)];
    const std::filesystem::path path = "../assets/" + directory;

    if (!std::filesystem::exists(path)) {
        std::cerr << "Folder is not found " << path << '\n';
        return 1;
    }

    ref.resize(enumSize<T>());

    for (const auto& entry :
         std::filesystem::recursive_directory_iterator(path,
                                          std::filesystem::directory_options::skip_permission_denied)) // TODO: redo
    {
        if (entry.is_regular_file()) {
            std::string filePath = entry.path().string();
            std::string name = entry.path().stem().string();
            int id = std::to_underlying(map.at(name)); // TODO: except

            if (!ref[id].loadFromFile(filePath))
            {
                std::cerr << "Failed to load: " << filePath << '\n';
                return -1;
            }
        }
    }
    return 0;
}

