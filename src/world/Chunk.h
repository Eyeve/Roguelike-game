#ifndef ROGUELIKE_GAME_CHUNK_H
#define ROGUELIKE_GAME_CHUNK_H

#include <array>

#include "TextureManager.h"
#include "TileManager.h"

struct Chunk
{
    static constexpr uint32_t SIZE = 32;
    std::array<std::array<Tile, SIZE>, SIZE> tiles;
};

#endif
