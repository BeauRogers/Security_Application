#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>

class Button {
public:
    Button(float x, float y, float width, float height, const sf::Color& color, const std::string& buttonName);
    void draw(sf::RenderWindow& window);
    bool isMouseOver(const sf::RenderWindow& window);
    void handleHover(const sf::RenderWindow& window);
    void handleClick();

private:
    sf::RectangleShape shape;
    sf::Color originalColor;
    std::string name;
};

#endif // BUTTON_H 