#include <fstream>

#include "BiomeManager.h"
#include "Utility.h"

BiomeManager::BiomeManager() : biomes(enumSize<BiomeType>())
{
}

int BiomeManager::init()
{
    nlohmann::json config;
    std::ifstream in("../config/config.json");

    in >> config;
    const nlohmann::json& biomesConfig = config["biomes"];

    addBiome(biomesConfig, BiomeType::Cave, "Cave");
    return 0;
}

const Biome& BiomeManager::getHandler(BiomeType name) const
{
    return biomes[std::to_underlying(name)];
}

NLOHMANN_JSON_SERIALIZE_ENUM(TileType, {{TileType::Floor, "Floor"},
                                        {TileType::Ceil, "Ceil"},
                                        {TileType::Up, "Up"},
                                        {TileType::Right, "Right"},
                                        {TileType::Down, "Down"},
                                        {TileType::Left, "Left"},
                                        {TileType::InUpRight, "InUpRight"},
                                        {TileType::InUpLeft, "InUpLeft"},
                                        {TileType::InDownRight, "InDownRight"},
                                        {TileType::InDownLeft, "InDownLeft"},
                                        {TileType::OutUpRight, "OutUpRight"},
                                        {TileType::OutUpLeft, "OutUpLeft"},
                                        {TileType::OutDownRight, "OutDownRight"},
                                        {TileType::OutDownLeft, "OutDownLeft"},
                                        {TileType::None, "None"}})

void BiomeManager::addBiome(const nlohmann::json& biomesConfig, BiomeType biomeType, const std::string& name)
{
    Biome& biome = biomes[std::to_underlying(biomeType)];
    const nlohmann::json& biomeConfig = biomesConfig[name];

    for (auto& rule : biomeConfig["rules"])
    {
        biome.rules.emplace_back(rule["tile"].get<TileType>(), rule["upRight"].get<bool>(), rule["upLeft"].get<bool>(),
                                 rule["downRight"].get<bool>(), rule["downLeft"].get<bool>());
    }
    for (auto& structure : biomeConfig["structures"])
    {
        biome.structures.emplace_back(structure["weight"].get<float>(),
                                      structure["tiles"].get<std::vector<std::vector<TileType>>>());
    }
}
