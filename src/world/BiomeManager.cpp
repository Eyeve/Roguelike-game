#include "BiomeManager.h"

#include "Utility.h"


BiomeManager::BiomeManager(): biomes(enumSize<BiomeName>()) {

}

int BiomeManager::init() {
    addBiome(
        BiomeName::Cave,
        {
            Weight(TextureName::Floor, 1),
            Weight(TextureName::Ceil, 1),
            Weight(TextureName::Up, 1),
            Weight(TextureName::Down, 1),
            Weight(TextureName::Right, 1),
            Weight(TextureName::Left, 1),
            Weight(TextureName::OutUpRight, 1),
            Weight(TextureName::OutUpLeft, 1),
            Weight(TextureName::OutDownRight, 1),
            Weight(TextureName::OutDownLeft, 1),
            Weight(TextureName::InUpRight, 1),
            Weight(TextureName::InUpLeft, 1),
            Weight(TextureName::InDownRight, 1),
            Weight(TextureName::InDownLeft, 1),
        },
        {
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

