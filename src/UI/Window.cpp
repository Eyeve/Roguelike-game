#include <SFML/Graphics.hpp>

#include "Window.h"


Window::Window(): sprites(WIDTH, std::vector<sf::Sprite>(HEIGHT, sf::Sprite())) {
    sf::VideoMode videoMode(PIXELS_PER_CELL * WIDTH, PIXELS_PER_CELL * HEIGHT);
    window.create(videoMode, TITLE);
    window.setFramerateLimit(FRAME_LIMIT);
    view = window.getDefaultView();

    manager.init();

    for (uint32_t x = 0; x < WIDTH; ++x) {
        for (uint32_t y = 0; y < HEIGHT; ++y) {
            auto xPos = static_cast<float>(x * PIXELS_PER_CELL);
            auto yPos = static_cast<float>(y * PIXELS_PER_CELL);
            sprites[x][y].setPosition(xPos, yPos);


            sprites[x][y].setTexture(manager.getTexture(Player));
            sprites[x][y].setScale(0.01f, 0.01f);
        }
    }
}

void Window::eventHandlerLoop() {
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        for (uint32_t x = 0; x < WIDTH; ++x) {
            for (uint32_t y = 0; y < HEIGHT; ++y) {
                window.draw(sprites[x][y]);
            }
        }
        window.display();
    }
}

void Window::update(uint32_t x, uint32_t y, const sf::Texture &texture) {

}

