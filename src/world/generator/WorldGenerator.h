#ifndef ROGUELIKE_GAME_WORLD_GENERATOR_H
#define ROGUELIKE_GAME_WORLD_GENERATOR_H

#include <random>

#include "WorldGeneratorInterface.h"


struct TileInfo {
    static constexpr uint8_t LEN = 14;

    float entropy = 0.0f;
    uint8_t len = LEN;
    std::array<Tile, LEN> variants = {};
};


class WorldGenerator: public WorldGeneratorInterface {
public:
    explicit WorldGenerator(uint32_t seed);

    Chunk generate(int32_t xChunk, int32_t yChunk) override;

private:
    std::mt19937 gen;

    void updateGen(int32_t xChunk, int32_t yChunk);
    Chunk noDependenciesGeneration(int32_t xChunk, int32_t yChunk);
    Chunk verticalDependenceGeneration(int32_t xChunk, int32_t yChunk);
    Chunk horizontalDependenceGeneration(int32_t xChunk, int32_t yChunk);
    Chunk fullDependenciesGeneration(int32_t xChunk, int32_t yChunk);
};


#endif
