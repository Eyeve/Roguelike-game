#include "TestRoomGenerator.h"

TestRoomGenerator::TestRoomGenerator() : WorldGeneratorInterface(0)
{
}

Chunk TestRoomGenerator::generate(int32_t x, int32_t y)
{
    Chunk chunk;
    for (uint32_t i = 0; i < Chunk::SIZE; ++i)
    {
        for (uint32_t j = 0; j < Chunk::SIZE; ++j)
        {
            chunk.tiles[i][j].type = TileType::Ceil;
        }
    }

    if (x == 0 && y == 0)
    {
        for (uint32_t i = 0; i < ROOM.size(); i++)
        {
            for (uint32_t j = 0; j < ROOM[i].size(); j++)
            {
                chunk.tiles[i + 18][j + 8].type = ROOM[j][i];
            }
        }
    }
    return chunk;
}
