#include "WorldGenerator.h"

WorldGenerator::WorldGenerator(uint32_t seed): WorldGeneratorInterface(seed) {

}

Chunk WorldGenerator::generate(int32_t x, int32_t y) {
    bool verticalDependence = x % 2;
    bool horizontalDependence = y % 2;
    if (verticalDependence && horizontalDependence) return fullDependenciesGeneration(x, y);
    if (verticalDependence) return verticalDependenceGeneration(x, y);
    if (horizontalDependence) return horizontalDependenceGeneration(x, y);
    return noDependenciesGeneration(x, y);
}
