#include "button.h"
#include <iostream>

Button::Button(float x, float y, float width, float height, const sf::Color& color, const std::string& buttonName) 
    : name(buttonName) {
    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(sf::Vector2f(x, y));
    shape.setFillColor(color);
    originalColor = color;
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(shape);
}

bool Button::isMouseOver(const sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosFloat(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    return shape.getGlobalBounds().contains(mousePosFloat);
}

void Button::handleHover(const sf::RenderWindow& window) {
    if (isMouseOver(window)) {
        // Darken the button when hovered
        sf::Color darkerColor = originalColor;
        darkerColor.r = static_cast<std::uint8_t>(darkerColor.r * 0.8);
        darkerColor.g = static_cast<std::uint8_t>(darkerColor.g * 0.8);
        darkerColor.b = static_cast<std::uint8_t>(darkerColor.b * 0.8);
        shape.setFillColor(darkerColor);
    } else {
        shape.setFillColor(originalColor);
    }
}

void Button::handleClick() {
    std::cout << "nothing" << std::endl;
    if (name == "Enter") {
        std::cout << "Enter button clicked! Transitioning to main screen..." << std::endl;
    } else if (name == "Red Button") {
        std::cout << "Red button clicked! Starting security scan..." << std::endl;
    } else if (name == "Green Button") {
        std::cout << "Green button clicked! Initializing system check..." << std::endl;
    } else if (name == "Blue Button") {
        std::cout << "Blue button clicked! Running diagnostics..." << std::endl;
    } else if (name == "Yellow Button") {
        std::cout << "Yellow button clicked! Generating report..." << std::endl;
    }
} 