#include "BiomeManager.h"

#include "Utility.h"


BiomeManager::BiomeManager(): biomes(enumSize<BiomeName>()) {

}

int BiomeManager::init() {
    addBiome(
        BiomeName::Cave,
        {
            Weight(TileType::Floor, 1),
            Weight(TileType::Ceil, 1),
            Weight(TileType::Up, 1),
            Weight(TileType::Down, 1),
            Weight(TileType::Right, 1),
            Weight(TileType::Left, 1),
            Weight(TileType::OutUpRight, 1),
            Weight(TileType::OutUpLeft, 1),
            Weight(TileType::OutDownRight, 1),
            Weight(TileType::OutDownLeft, 1),
            Weight(TileType::InUpRight, 1),
            Weight(TileType::InUpLeft, 1),
            Weight(TileType::InDownRight, 1),
            Weight(TileType::InDownLeft, 1),
        },
        {
            Rule()
        }
    );
    return 0;
}

const Biome& BiomeManager::getHandler(BiomeName name) {
    return biomes[std::to_underlying(name)];
}

void BiomeManager::addBiome(BiomeName name, const std::vector<Weight> &weights, const std::vector<Rule> &rules) {
    Biome& ref = biomes[std::to_underlying(name)];
    ref.weights = weights;
    ref.rules = rules;
}

