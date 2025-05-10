#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "button.h"
#include <stdlib.h>

class MainScreen {
public:
    MainScreen(sf::RenderWindow& window);
    void handleEvent(const std::optional<sf::Event>& event);
    void update();
    void draw();

private:
    sf::RenderWindow& window;
    std::vector<Button> buttons;
    bool isMainScreen;
}; 