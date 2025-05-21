#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>

class Button {
public:
    Button(float x, float y, float width, float height, const sf::Color& color, 
           const std::string& buttonName, const std::string& primary = "",
           const std::string& secondary = "", const std::string& tertiary = "",
           const std::string& local_police = "");
    void draw(sf::RenderWindow& window);
    bool isMouseOver(const sf::RenderWindow& window);
    void handleHover(const sf::RenderWindow& window);
    void handleClick();

private:
    sf::RectangleShape shape;
    sf::Color originalColor;
    std::string name;
    std::string labelMe;
    std::string primary;
    std::string secondary;
    std::string tertiary;
    std::string local_police;
    sf::Font font;
};

#endif // BUTTON_H 