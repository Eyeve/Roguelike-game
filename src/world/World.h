#ifndef ROGUELIKE_GAME_WORLD_H
#define ROGUELIKE_GAME_WORLD_H

#include <SFML/System/Vector2.hpp>
#include <unordered_map>

#include "Chunk.h"
#include "WorldGeneratorInterface.h"

enum class Direction
{
    // TODO: Move to utility
    Up,
    Right,
    Down,
    Left,
    Up_Right,
    Up_Left,
    Down_Right,
    Down_Left,

    None,
};

class World
{
    friend class WorldGeneratorInterface;

  public:
    explicit World(const WorldGeneratorInterface& gen);

  private:
    std::unordered_map<sf::Vector2<int32_t>, Chunk> chunks;
};

#endif
