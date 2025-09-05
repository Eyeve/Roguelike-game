#ifndef ROGUELIKE_GAME_TEST_ROOM_GENERATOR_H
#define ROGUELIKE_GAME_TEST_ROOM_GENERATOR_H

#define ROW(name1, name2, name3, name4) std::array<TextureName, 4> {TextureName::name1, TextureName::name2, TextureName::name3, TextureName::name4}

#include "WorldGeneratorInterface.h"

class TestRoomGenerator: public WorldGeneratorInterface {
public:
    static constexpr std::array<std::array<TextureName, 4>, 4> ROOM = {
        ROW(InUpLeft, Down, Down, InUpRight),
        ROW(Right, Floor, Floor, Left),
        ROW(Right, Floor, Floor, Left),
        ROW(InDownLeft, Up, Up, InDownRight)
    };

    TestRoomGenerator();

    Chunk generate(int32_t x, int32_t y) override;
};


#endif
