#ifndef ROGUELIKE_GAME_WINDOW_H
#define ROGUELIKE_GAME_WINDOW_H

#include <cinttypes>

#include "TextureManager.h"

class Window
{
  public:
    static constexpr uint32_t HEIGHT = 21;
    static constexpr uint32_t WIDTH = 41;
    static constexpr uint32_t PIXELS_PER_TILE = 8;
    static constexpr uint32_t FRAME_LIMIT = 60;
    static constexpr const char* TITLE = "Game";

    Window();

    void eventHandlerLoop();

    void update(uint32_t x, uint32_t y, const sf::Texture& texture);

  private:
    sf::RenderWindow window;
    sf::View view;
    std::vector<std::vector<sf::Sprite>> sprites;
    TextureManager manager;
};

#endif