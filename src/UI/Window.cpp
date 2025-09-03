#include <SFML/Graphics.hpp>

#include "Window.h"


Window::Window() {
    sf::VideoMode videoMode(PIXELS_PER_CELL * WIDTH, PIXELS_PER_CELL * HEIGHT);
    window.create(videoMode, TITLE);
    window.setFramerateLimit(FRAME_LIMIT);
    view = window.getDefaultView();
}

void Window::eventHandlerLoop() {
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }
}

