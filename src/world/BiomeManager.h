#ifndef ROGUELIKE_GAME_BIOME_MANAGER_H
#define ROGUELIKE_GAME_BIOME_MANAGER_H

#define TT(type) TileType::type

#include "Utility.h"
#include "World.h"


struct Rule {
    TileType condition;
    std::vector<std::vector<TileType>> bans;

    Rule(): condition(), bans(4) {} // TODO: del magic num
    Rule(TileType condition, const std::vector<std::vector<TileType>>& bans):
        condition(condition), bans(bans) {}
};

struct Weight {
    TileType texture;
    float weight;

    Weight(): texture(), weight(0.0f) {}
    Weight(TileType texture, float weight): texture(texture), weight(weight) {}
};

struct Structure {
    float weight;
    std::vector<std::vector<TileType>> tiles;
};

struct Biome {
    std::vector<Weight> weights;
    std::vector<Rule> neighborhoodRules;
    std::vector<Structure> structures;

    Biome(): weights(), neighborhoodRules() {}
    Biome(const std::vector<Weight>& weights, const std::vector<Rule>& neighborhoodRules, const std::vector<Structure>& structures):
        weights(weights), neighborhoodRules(neighborhoodRules), structures(structures) {}
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

    void addBiome(BiomeName name, const std::vector<Weight>& weights, const std::vector<Rule>& neighborhoodRules);
};

#endif
