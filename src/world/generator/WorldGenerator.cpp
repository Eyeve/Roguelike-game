#include "WorldGenerator.h"

#include <queue>
#include <random>


WorldGenerator::WorldGenerator(uint32_t seed, const BiomeManager& biomeManager): WorldGeneratorInterface(seed), biome() {
    biome = biomeManager.get(BiomeType::Cave);
}

Chunk WorldGenerator::generate(int32_t xChunk, int32_t yChunk) {
    bool verticalDependence = xChunk % 2;
    bool horizontalDependence = yChunk % 2;

    if (verticalDependence) {
        generate(xChunk, yChunk + 1);
        generate(xChunk, yChunk - 1);
    }
    if (horizontalDependence) {
        generate(xChunk + 1, yChunk);
        generate(xChunk - 1, yChunk);
    }

    updateGen(xChunk, yChunk);
    if (verticalDependence && horizontalDependence) return fullDependenciesGeneration(xChunk, yChunk);
    if (verticalDependence) return verticalDependenceGeneration(xChunk, yChunk);
    if (horizontalDependence) return horizontalDependenceGeneration(xChunk, yChunk);
    return noDependenciesGeneration(xChunk, yChunk);
}

void WorldGenerator::updateGen(int32_t xChunk, int32_t yChunk) {
    std::seed_seq seq {
        static_cast<uint32_t>(xChunk),
        static_cast<uint32_t>(yChunk),
        seed
    };
    gen.seed(seq);
}


Chunk WorldGenerator::noDependenciesGeneration(int32_t xChunk, int32_t yChunk) {
    std::array<std::array<TileInfo, Chunk::SIZE>, Chunk::SIZE> tilesInfo = {};
    std::priority_queue<UnsetTile, std::vector<UnsetTile>, std::greater<>> minHeap;

    std::vector<StructurePosition> startVariants;
    for (uint32_t id = 0; id < biome.structures.size(); ++id) {
        const Structure& structure = biome.structures[id];
        for (uint32_t xStruct = 0; xStruct < structure.tiles.size(); ++xStruct) { // TODO: transpose
            for (uint32_t yStruct = 0; yStruct < structure.tiles[xStruct].size(); ++yStruct) {
                if (structure.tiles[xStruct][yStruct] != TileType::None) {
                    startVariants.emplace_back(id, xStruct, yStruct);
                }
            }
        }
    }
    float startEntropy = getEntropy(startVariants);

    for (uint32_t x = 0; x < Chunk::SIZE; ++x) {
        for (uint32_t y = 0; y < Chunk::SIZE; ++y) {
            tilesInfo[x][y].variants = startVariants;
            tilesInfo[x][y].entropy = startEntropy;
            minHeap.emplace(startEntropy, x, y);
        }
    }

    while (!minHeap.empty()) {
        UnsetTile unsetTile = minHeap.top();
        if (std::abs(unsetTile.entropy) < 0.001)
            return noDependenciesGeneration(xChunk, yChunk);

        std::vector<float> weights;
        for (auto& variant: tilesInfo[unsetTile.x][unsetTile.y].variants) {
            weights.push_back(biome.structures[variant.id].weight);
        }

        std::discrete_distribution dist(weights.begin(), weights.end());
        StructurePosition structPos = tilesInfo[unsetTile.x][unsetTile.y].variants[dist(gen)];
        // TODO: разместить структуру и пересчитать варианты, энтропию
        minHeap.pop();
    }

    std::uniform_int_distribution<int32_t> dist(0, Chunk::SIZE);
    int32_t x = dist(gen);
    int32_t y = dist(gen);


}

Chunk WorldGenerator::verticalDependenceGeneration(int32_t xChunk, int32_t yChunk) {

}

Chunk WorldGenerator::horizontalDependenceGeneration(int32_t xChunk, int32_t yChunk) {

}

Chunk WorldGenerator::fullDependenciesGeneration(int32_t xChunk, int32_t yChunk) {

}

float WorldGenerator::getEntropy(const std::vector<StructurePosition>& structurePositions) {
    float entropy = 0.0f;
    float totalWeight = 0.0f;
    for (const StructurePosition& structurePosition : structurePositions) {
        totalWeight += biome.structures[structurePosition.id].weight;
    }
    for (const StructurePosition& structurePosition : structurePositions) {
        float p = biome.structures[structurePosition.id].weight / totalWeight;
        entropy -= p * std::log2f(p);
    }
    return entropy;
}

