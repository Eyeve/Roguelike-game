#ifndef ROGUELIKE_GAME_WORLD_H
#define ROGUELIKE_GAME_WORLD_H

#include <unordered_map>
#include <SFML/System/Vector2.hpp>

#include "Chunk.h"
#include "WorldGenerator.h"


class World {
public:
    explicit World(const WorldGeneratorInterface& gen);

private:
    std::unordered_map<sf::Vector2<int32_t>, Chunk> chunks;
};

#endif
