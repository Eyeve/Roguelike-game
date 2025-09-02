#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Создаём окно 800x600, заголовок и ограничение частоты кадров
    sf::RenderWindow window(sf::VideoMode(800, 600), "My SFML Window");
    window.setFramerateLimit(60);

    // Опционально: иконка (пример, если есть файл icon.png)
    // sf::Image icon;
    // if (icon.loadFromFile("icon.png")) {
    //     window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    // }

    // Небольшой объект для наглядности (красный круг)
    sf::CircleShape circle(70.f);
    circle.setFillColor(sf::Color(220, 20, 60));
    circle.setPosition(365.f, 265.f); // по центру примерно

    // Главный цикл
    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            // Закрытие окна
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Нажатие клавиш
            if (event.type == sf::Event::KeyPressed) {
                // Выход по Esc
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }

            // Изменение размера окна — можно подстроить вьюпорт
            if (event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, static_cast<float>(event.size.width), static_cast<float>(event.size.height));
                window.setView(sf::View(visibleArea));
            }
        }

        // Обновление логики (пример — лёгкая анимация позиции)
        // circle.move(0.1f, 0.f); // раскомментируйте для движения

        // Отрисовка
        window.clear(sf::Color(30, 30, 30)); // фон
        window.draw(circle);                  // ваши объекты
        window.display();                     // вывод на экран
    }

    return 0;
}