#ifndef ROGUELIKE_GAME_WORLD_GENERATOR_H
#define ROGUELIKE_GAME_WORLD_GENERATOR_H

#include <random>

#include "BiomeManager.h"
#include "WorldGeneratorInterface.h"


struct StructurePosition {
    int id;
    int x;
    int y;

    StructurePosition(): id(0), x(0), y(0) {}
    StructurePosition(int id, int x, int y) : id(id), x(x), y(y) {}
};

struct TileInfo {
    float entropy;
    std::vector<StructurePosition> variants;

    TileInfo(): entropy(0.0f), variants() {};
    TileInfo(float entropy, const std::vector<StructurePosition>& variants) : entropy(entropy), variants(variants) {};
};

struct UnsetTile {
    float entropy;
    int x;
    int y;

    UnsetTile(): entropy(0.0f), x(0), y(0) {}
    UnsetTile(float entropy, int x, int y): entropy(entropy), x(x), y(y) {}
    bool operator>(const UnsetTile& other) const { return entropy > other.entropy; } // TODO: maybe redo
};


class WorldGenerator: public WorldGeneratorInterface {
public:
    WorldGenerator(uint32_t seed, const BiomeManager& biomeManager);

    Chunk generate(int32_t xChunk, int32_t yChunk) override;

private:
    std::mt19937 gen;
    Biome biome;

    void updateGen(int32_t xChunk, int32_t yChunk);
    Chunk noDependenciesGeneration(int32_t xChunk, int32_t yChunk);
    Chunk verticalDependenceGeneration(int32_t xChunk, int32_t yChunk);
    Chunk horizontalDependenceGeneration(int32_t xChunk, int32_t yChunk);
    Chunk fullDependenciesGeneration(int32_t xChunk, int32_t yChunk);
    float getEntropy(const std::vector<StructurePosition>& structurePositions);
};


#endif
