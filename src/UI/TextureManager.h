#ifndef ROGUELIKE_GAME_TEXTURE_MANAGER_H
#define ROGUELIKE_GAME_TEXTURE_MANAGER_H

#include <SFML/Graphics.hpp>
#include <utility>
#include <unordered_map>

#include "ManagerInterface.h"


enum class TextureType {
    Tileset,
    Creature,

    None
};

struct TextureKey {
    int type;
    int id;

    template <typename T>
    TextureKey(TextureType type, T name): type(std::to_underlying(type)), id(std::to_underlying(name)) {}
};

class TextureManager: public ManagerInterface<TextureKey, sf::Texture> {
public:
    TextureManager();

protected:
    int init() override;
    const sf::Texture& getHandler(TextureKey name) override;

private:
    std::vector<std::vector<sf::Texture>> textures;

    template<typename T>
    int textureSearch(const std::string& directory, TextureType type, const std::unordered_map<std::string, T>& map);
};

#endif
