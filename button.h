#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>
#include <functional>

class Button {
public:
    enum class ButtonType {
        CONTACT_LIST,
        PHONE_NUMBER
    };

    Button(float x, float y, float width, float height, const sf::Color& color, 
           const std::string& buttonName, ButtonType type,
           const std::string& primary = "",
           const std::string& secondary = "",
           const std::string& tertiary = "",
           const std::string& local_police = "");
    void draw(sf::RenderWindow& window);
    bool isMouseOver(const sf::RenderWindow& window);
    void handleHover(const sf::RenderWindow& window);
    void handleClick();
    ButtonType getType() const { return type; }
    const std::string& getName() const { return name; }

private:
    sf::RectangleShape shape;
    sf::Color originalColor;
    std::string name;
    ButtonType type;
    std::string primary;
    std::string secondary;
    std::string tertiary;
    std::string local_police;
    sf::Font font;
    std::string labelMe;
};

#endif // BUTTON_H 