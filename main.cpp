#include <SFML/Graphics.hpp>
#include "main_screen.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({600, 600}), "Appa Security");
    MainScreen mainScreen(window);

    while (window.isOpen()) 
    {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            mainScreen.handleEvent(event);
        }

        mainScreen.update();

        window.clear(sf::Color::White);
        mainScreen.draw();
        window.display();
    }

    return 0;
}