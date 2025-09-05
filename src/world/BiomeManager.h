#ifndef ROGUELIKE_GAME_BIOME_MANAGER_H
#define ROGUELIKE_GAME_BIOME_MANAGER_H

#include <nlohmann/json.hpp>

#include "World.h"


struct Rule {
    TileType tile;
    bool upRight;
    bool upLeft;
    bool downRight;
    bool downLeft;

    Rule(): tile(TileType::None), upRight(false), upLeft(false), downRight(false), downLeft(false) {}
    Rule(TileType tile, bool upRight, bool upLeft, bool downRight, bool downLeft):
        tile(tile), upRight(upRight), upLeft(upLeft), downRight(downRight), downLeft(downLeft) {}
};

struct Structure {
    float weight;
    std::vector<std::vector<TileType>> tiles;

    Structure(): weight(0.0f), tiles() {}
    Structure(float weight, const std::vector<std::vector<TileType>>& tiles): weight(weight), tiles(tiles) {};
};

struct Biome {
    std::vector<Rule> rules;
    std::vector<Structure> structures;

    Biome(): rules(), structures() {}
    Biome(const std::vector<Rule>& rules, const std::vector<Structure>& structures): rules(rules), structures(structures) {}
};

enum class BiomeType {
    Cave,

    None
};

class BiomeManager: public ManagerInterface<BiomeType, Biome> {

public:
    BiomeManager();

protected:
    int init() override;
    const Biome& getHandler(BiomeType name) override;

private:
    std::vector<Biome> biomes;

    void addBiome(const nlohmann::json& biomesConfig, BiomeType biomeType, const std::string& name);
};

#endif
