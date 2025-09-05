#ifndef ROGUELIKE_GAME_WORLD_H
#define ROGUELIKE_GAME_WORLD_H

#include <unordered_map>
#include <SFML/System/Vector2.hpp>

#include "Chunk.h"
#include "WorldGeneratorInterface.h"


enum class Direction {
    Up,
    Down,
    Left,
    Right,
    Up_Right,
    Up_Left,
    Down_Right,
    Down_Left,

    None,
};

class World {
public:
    explicit World(const WorldGeneratorInterface& gen);

private:
    std::unordered_map<sf::Vector2<int32_t>, Chunk> chunks;
};

#endif
