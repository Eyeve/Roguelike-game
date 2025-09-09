#include <SFML/Graphics.hpp>
#include <iostream>

#include "BiomeManager.h"
#include "TestRoomGenerator.h"
#include "Window.h"
#include "World.h"

int main()
{

    BiomeManager biomeManager;
    biomeManager.initialize();

    Window window;
    TestRoomGenerator gen;
    TextureManager manager;
    manager.initialize();
    Chunk chunk = gen.generate(0, 0);

    for (int x = 0; x < std::min(Window::WIDTH, Chunk::SIZE); ++x)
    {
        for (int y = 0; y < std::min(Window::HEIGHT, Chunk::SIZE); ++y)
        {
            window.update(x, y, manager.get({TextureType::Tileset, chunk.tiles[x][y].type}));
        }
    }
    window.eventHandlerLoop();

    // sf::RenderWindow window(sf::VideoMode(800, 600), "2D Бродилка");
    // window.setFramerateLimit(60);
    //
    // sf::Texture playerTexture;
    // if (!playerTexture.loadFromFile("assets/player.png")) {
    //     std::cerr << "Не удалось загрузить текстуру\n";
    //     return -1;
    // }
    //
    // sf::Sprite player(playerTexture);
    // player.setPosition(0, 0);
    // player.setScale(0.1f, 0.1f);
    //
    // sf::View view = window.getDefaultView();
    // sf::Clock clock;
    //
    // while (window.isOpen()) {
    //     sf::Event event{};
    //     while (window.pollEvent(event)) {
    //         if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    //             window.close();
    //     }
    //
    //     float dt = clock.restart().asSeconds();
    //     float speed = 200.0f;
    //
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    //         player.move(speed * dt, 0);
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    //         player.move(-speed * dt, 0);
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    //         player.move(0, -speed * dt);
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    //         player.move(0, speed * dt);
    //
    //     // view.setCenter(player.getPosition());
    //     // window.setView(view);
    //
    //     window.clear();
    //     window.draw(player);
    //     window.display();
    // }

    return 0;
}
