#ifndef ROGUELIKE_GAME_BIOME_MANAGER_H
#define ROGUELIKE_GAME_BIOME_MANAGER_H

#include "World.h"


struct Rule {
    TextureName condition;
    TextureName ban;
    Direction dir;

    Rule(): condition(), ban(), dir(Direction::Up) {}
    Rule(TextureName condition, TextureName ban, Direction dir): condition(condition), ban(ban), dir(dir) {}
};

struct Weight {
    TextureName texture;
    float weight;

    Weight(): texture(), weight(0.0f) {}
    Weight(TextureName texture, float weight): texture(texture), weight(weight) {}
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
