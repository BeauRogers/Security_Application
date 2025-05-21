#include "main_screen.h"
#include <iostream>

MainScreen::MainScreen(sf::RenderWindow& window) : window(window), isMainScreen(false) {
    loadContacts();
    createContactButtons();
}

void MainScreen::loadContacts() {
    try {
        std::ifstream file("contacts.json");
        if (!file.is_open()) {
            std::cerr << "Error opening contacts.json" << std::endl;
            return;
        }

        nlohmann::json json;
        file >> json;

        for (const auto& contact : json["contacts"]) {
            Contact c;
            c.name = contact["name"];
            c.address = contact["address"];
            c.primary = contact["primary"];
            c.secondary = contact["secondary"];
            c.tertiary = contact["tertiary"];
            c.local_police = contact["local_police"];
            c.code_name = contact["code_name"];
            contacts.push_back(c);
        }
    } catch (const std::exception& e) {
        std::cerr << "Error loading contacts: " << e.what() << std::endl;
    }
}

void MainScreen::createContactButtons() {
    float buttonWidth = window.getSize().x * 0.75f;  // 75% of window width
    float buttonHeight = 50.0f;
    float buttonSpacing = 20.0f;
    float totalHeight = (buttonHeight * contacts.size()) + (buttonSpacing * (contacts.size() - 1));
    float startY = (window.getSize().y - totalHeight) / 2.0f;

    for (size_t i = 0; i < contacts.size(); ++i) {
        buttons.emplace_back(
            (window.getSize().x - buttonWidth) / 2.0f,
            startY + (buttonHeight + buttonSpacing) * i,
            buttonWidth,
            buttonHeight,
            sf::Color(100, 100, 100),
            contacts[i].code_name,
            contacts[i].primary,
            contacts[i].secondary,
            contacts[i].tertiary,
            contacts[i].local_police
        );
    }
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