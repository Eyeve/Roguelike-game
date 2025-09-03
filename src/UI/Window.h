#ifndef ROGUELIKE_GAME_WINDOW_H
#define ROGUELIKE_GAME_WINDOW_H

#include <cinttypes>


class Window {
public:
    static constexpr uint32_t HEIGHT = 40;
    static constexpr uint32_t WIDTH = 40;
    static constexpr uint32_t PIXELS_PER_CELL = 20;
    static constexpr uint32_t FRAME_LIMIT = 60;
    static constexpr const char* TITLE = "Game";

    Window();

    void eventHandlerLoop();
    // void update(uint32_t x, uint32_t y, );

private:
    sf::RenderWindow window;
    sf::View view;
};


#endif //ROGUELIKE_GAME_WINDOW_H