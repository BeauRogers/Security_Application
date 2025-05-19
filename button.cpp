#include "button.h"
#include <iostream>

Button::Button(float x, float y, float width, float height, const sf::Color& color, const std::string& buttonName) 
    : name(buttonName), 
    shape() {
    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(sf::Vector2f(x, y));
    shape.setFillColor(color);
    originalColor = color;
    labelMe = buttonName;

    // Load the font
    if (!font.openFromFile("/System/Library/Fonts/Helvetica.ttc")) {
        std::cerr << "Error loading font" << std::endl;
    }
}

void Button::draw(sf::RenderWindow& window) {
    // Initialize text with font and string
    sf::Text text(font, labelMe, 24);
    text.setFillColor(sf::Color::White);

    // Center the text on the button
    sf::FloatRect textBounds = text.getLocalBounds();
    text.setPosition(
        {(shape.getSize().x - textBounds.size.x) / 2.0f,
        (shape.getSize().y - textBounds.size.y) / 2.0f}
    );
    window.draw(shape);
    window.draw(text);
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
    } else if (name == "Primary") {
        std::cout << "Primary button clicked! Starting security scan..." << std::endl;
    } else if (name == "Secondary") {
        std::cout << "Secondary button clicked! Initializing system check..." << std::endl;
    } else if (name == "Tertiary") {
        std::cout << "Tertiary button clicked! Running diagnostics..." << std::endl;
    } else if (name == "Local Police") {
        std::cout << "Local Police button clicked! Generating report..." << std::endl;
    }
} 