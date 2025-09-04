#ifndef ROGUELIKE_GAME_WORLDGENERATOR_H
#define ROGUELIKE_GAME_WORLDGENERATOR_H

#include "WorldGeneratorInterface.h"


class WorldGenerator: public WorldGeneratorInterface {
public:
    explicit WorldGenerator(uint32_t seed);

    Chunk generate(int32_t x, int32_t y) override;
};


#endif