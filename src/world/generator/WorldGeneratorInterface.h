#ifndef ROGUELIKE_GAME_WORLD_GENERATOR_INTERFACE_H
#define ROGUELIKE_GAME_WORLD_GENERATOR_INTERFACE_H

#include "Chunk.h"


class WorldGeneratorInterface {

public:
    virtual Chunk generate(int32_t xChunk, int32_t yChunk) = 0;

protected:
    uint32_t seed;

    explicit WorldGeneratorInterface(uint32_t seed): seed(seed) {}
    virtual ~WorldGeneratorInterface() = default;
};

#endif
