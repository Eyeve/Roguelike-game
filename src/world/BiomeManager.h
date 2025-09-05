#ifndef ROGUELIKE_GAME_BIOME_MANAGER_H
#define ROGUELIKE_GAME_BIOME_MANAGER_H

#include "World.h"


struct Rule {
    TileType condition;
    TileType possible;
    Direction dir;

    Rule(): condition(), possible(), dir(Direction::Up) {}
    Rule(TileType condition, TileType possible, Direction dir): condition(condition), possible(possible), dir(dir) {}
};

struct Weight {
    TileType texture;
    float weight;

    Weight(): texture(), weight(0.0f) {}
    Weight(TileType texture, float weight): texture(texture), weight(weight) {}
};

struct Biome {
    std::vector<Weight> weights;
    std::vector<Rule> rules;

    Biome(): weights(), rules() {}
    Biome(const std::vector<Weight>& weights, const std::vector<Rule>& rules): weights(weights), rules(rules) {}
};

enum class BiomeName {
    Cave,

    None
};

class BiomeManager: public ManagerInterface<BiomeName, Biome> {

public:
    BiomeManager();

protected:
    int init() override;
    const Biome& getHandler(BiomeName name) override;

private:
    std::vector<Biome> biomes;

    void addBiome(BiomeName name, const std::vector<Weight>& weights, const std::vector<Rule>& rules);
};

#endif
