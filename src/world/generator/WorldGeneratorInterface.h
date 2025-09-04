#ifndef ROGUELIKE_GAME_WORLDGENERATORINTERFACE_H
#define ROGUELIKE_GAME_WORLDGENERATORINTERFACE_H

#include "Chunk.h"

class WorldGeneratorInterface {

public:
    virtual Chunk generate(int32_t x, int32_t y) = 0;

protected:
    explicit WorldGeneratorInterface(uint32_t seed): seed(seed) {}
    virtual ~WorldGeneratorInterface() = default;

    uint32_t seed;
};

#endif