#include "main_screen.h"
#include <iostream>

MainScreen::MainScreen(sf::RenderWindow& window) : window(window), isMainScreen(false) {
    // Create the Enter button for the initial screen
    float enterButtonWidth = window.getSize().x * 0.3f;  // 30% of window width
    float enterButtonHeight = 50.0f;
    float enterButtonX = (window.getSize().x - enterButtonWidth) / 2.0f;
    float enterButtonY = (window.getSize().y - enterButtonHeight) / 2.0f;
    
    buttons.emplace_back(enterButtonX, enterButtonY, enterButtonWidth, enterButtonHeight, 
                        sf::Color(100, 100, 100), "Enter");
}

void MainScreen::handleEvent(const std::optional<sf::Event>& event) {
    //if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    if (event->is<sf::Event::MouseButtonPressed>())
    {
        for (auto& button : buttons) {
            if (button.isMouseOver(window)) {
                button.handleClick();
                if (!isMainScreen) {
                    // Clear existing buttons and create the main screen buttons
                    buttons.clear();
                    isMainScreen = true;
                    
                    // Create the four colored buttons
                    float buttonWidth = window.getSize().x * 0.75f;  // 75% of window width
                    float buttonHeight = 50.0f;
                    float buttonSpacing = 20.0f;
                    float totalHeight = (buttonHeight * 4) + (buttonSpacing * 3);
                    float startY = (window.getSize().y - totalHeight) / 2.0f;
                    
                    // Primary button (Red)
                    buttons.emplace_back((window.getSize().x - buttonWidth) / 2.0f, 
                                       startY, buttonWidth, buttonHeight, 
                                       sf::Color::Red, "Primary");
                    
                    // Secondary button (Green)
                    buttons.emplace_back((window.getSize().x - buttonWidth) / 2.0f, 
                                       startY + buttonHeight + buttonSpacing, 
                                       buttonWidth, buttonHeight, 
                                       sf::Color::Green, "Secondary");
                    
                    // Tertiary button (Blue)
                    buttons.emplace_back((window.getSize().x - buttonWidth) / 2.0f, 
                                       startY + (buttonHeight + buttonSpacing) * 2, 
                                       buttonWidth, buttonHeight, 
                                       sf::Color::Blue, "Tertiary");
                    
                    // Local Police button (Yellow)
                    buttons.emplace_back((window.getSize().x - buttonWidth) / 2.0f, 
                                       startY + (buttonHeight + buttonSpacing) * 3, 
                                       buttonWidth, buttonHeight, 
                                       sf::Color::Yellow, "Local Police");
                }
                break;
            }
        }
    }
}

void MainScreen::update() {
    for (auto& button : buttons) {
        button.handleHover(window);
    }
}

void MainScreen::draw() {
    for (auto& button : buttons) {
        button.draw(window);
    }
} 