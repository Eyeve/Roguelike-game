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
        },
        {
            Rule(
                TT(Ceil),
                {{TT(Down), TT(Floor), TT(Left), TT(Right),                                          TT(InUpLeft), TT(InUpRight), TT(OutUpRight), TT(OutUpLeft), TT(OutDownRight), TT(OutDownLeft)},
                { TT(Down), TT(Floor), TT(Left),            TT(Up),                 TT(InDownRight), TT(InUpRight), TT(OutUpRight), TT(OutUpLeft), TT(OutDownRight), TT(OutDownLeft)},
                {           TT(Floor), TT(Left), TT(Right), TT(Up), TT(InDownLeft), TT(InDownRight), TT(OutUpRight), TT(OutUpLeft), TT(OutDownRight), TT(OutDownLeft)},
                { TT(Down), TT(Floor),           TT(Right), TT(Up), TT(InDownLeft),                  TT(InUpLeft), TT(OutUpRight), TT(OutUpLeft), TT(OutDownRight), TT(OutDownLeft)}}
            ),
            Rule(
                TT(Floor),
                {{TT(Ceil)},
                {TT(Ceil), TT(Down),},
                {TT(Ceil), TT(Down),},
                {TT(Ceil), TT(Down),}}
            )
        }
    );
    return 0;
}

const Biome& BiomeManager::getHandler(BiomeName name) {
    return biomes[std::to_underlying(name)];
}

void BiomeManager::addBiome(BiomeName name, const std::vector<Weight> &weights, const std::vector<Rule> &neighborhoodRules) {
    Biome& ref = biomes[std::to_underlying(name)];
    ref.weights = weights;
    ref.neighborhoodRules = neighborhoodRules;
}

