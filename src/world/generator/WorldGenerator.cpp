#include "WorldGenerator.h"

#include <random>


WorldGenerator::WorldGenerator(uint32_t seed): WorldGeneratorInterface(seed) {

}

Chunk WorldGenerator::generate(int32_t xChunk, int32_t yChunk) {
    updateGen(xChunk, yChunk);

    bool verticalDependence = xChunk % 2;
    bool horizontalDependence = yChunk % 2;
    if (verticalDependence && horizontalDependence) return fullDependenciesGeneration(xChunk, yChunk);
    if (verticalDependence) return verticalDependenceGeneration(xChunk, yChunk);
    if (horizontalDependence) return horizontalDependenceGeneration(xChunk, yChunk);
    return noDependenciesGeneration(xChunk, yChunk);
}

void WorldGenerator::updateGen(int32_t x, int32_t y) {
    std::seed_seq seq {
        static_cast<uint32_t>(x),
        static_cast<uint32_t>(y),
        seed
    };
    gen.seed(seq);
}


Chunk WorldGenerator::noDependenciesGeneration(int32_t xChunk, int32_t yChunk) {

    std::array<std::array<CellInfo, Chunk::SIZE>, Chunk::SIZE> cellsInfo = {};

    std::uniform_int_distribution<uint32_t> dist(0, 10);

    for (int32_t x = 0; x < Chunk::SIZE; ++x) {
        for (int32_t y = 0; y < Chunk::SIZE; ++y) {

        }
    }
}

Chunk WorldGenerator::verticalDependenceGeneration(int32_t xChunk, int32_t yChunk) {

}

Chunk WorldGenerator::horizontalDependenceGeneration(int32_t xChunk, int32_t yChunk) {

}

Chunk WorldGenerator::fullDependenciesGeneration(int32_t xChunk, int32_t yChunk) {

}

