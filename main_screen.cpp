#include "main_screen.h"
#include <iostream>
#include <variant>
#include <cstdlib>

MainScreen::MainScreen(sf::RenderWindow& window) : window(window), currentScreen(main_screen) {
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
            Button::ButtonType::CONTACT_LIST,
            contacts[i].primary,
            contacts[i].secondary,
            contacts[i].tertiary,
            contacts[i].local_police
        );
    }
}

void MainScreen::createPhoneButtons(const Contact& contact) {
    buttons.clear();
    float buttonWidth = window.getSize().x * 0.75f;
    float buttonHeight = 50.0f;
    float buttonSpacing = 20.0f;
    float totalHeight = (buttonHeight * 5) + (buttonSpacing * 4); // Added space for back button
    float startY = (window.getSize().y - totalHeight) / 2.0f;

    // Back button (Gray)
    buttons.emplace_back(
        (window.getSize().x - buttonWidth) / 2.0f,
        startY,
        buttonWidth,
        buttonHeight,
        sf::Color(128, 128, 128), // Gray color
        "Back to Contacts",
        Button::ButtonType::BACK,
        contact.primary,
        contact.secondary,
        contact.tertiary,
        contact.local_police
    );

    // Primary button (Red)
    buttons.emplace_back(
        (window.getSize().x - buttonWidth) / 2.0f,
        startY + buttonHeight + buttonSpacing,
        buttonWidth,
        buttonHeight,
        sf::Color::Red,
        "Primary",
        Button::ButtonType::PHONE_NUMBER,
        contact.primary,
        contact.secondary,
        contact.tertiary,
        contact.local_police
    );

    // Secondary button (Green)
    buttons.emplace_back(
        (window.getSize().x - buttonWidth) / 2.0f,
        startY + (buttonHeight + buttonSpacing) * 2,
        buttonWidth,
        buttonHeight,
        sf::Color::Green,
        "Secondary",
        Button::ButtonType::PHONE_NUMBER,
        contact.primary,
        contact.secondary,
        contact.tertiary,
        contact.local_police
    );

    // Tertiary button (Blue)
    buttons.emplace_back(
        (window.getSize().x - buttonWidth) / 2.0f,
        startY + (buttonHeight + buttonSpacing) * 3,
        buttonWidth,
        buttonHeight,
        sf::Color::Blue,
        "Tertiary",
        Button::ButtonType::PHONE_NUMBER,
        contact.primary,
        contact.secondary,
        contact.tertiary,
        contact.local_police
    );

    // Local Police button (Yellow)
    buttons.emplace_back(
        (window.getSize().x - buttonWidth) / 2.0f,
        startY + (buttonHeight + buttonSpacing) * 4,
        buttonWidth,
        buttonHeight,
        sf::Color::Yellow,
        "Local Police",
        Button::ButtonType::PHONE_NUMBER,
        contact.primary,
        contact.secondary,
        contact.tertiary,
        contact.local_police
    );
}

void MainScreen::handleEvent(const std::optional<sf::Event>& event) {
    if (event->is<sf::Event::KeyPressed>()) {
        // Check for Command+C (Ctrl+C on Windows/Linux)
        const auto& keyEvent = event->getIf<sf::Event::KeyPressed>();
        if (keyEvent->code == sf::Keyboard::Key::C &&
            (keyEvent->control || keyEvent->system)) {
            window.close();
            return;
        }
    }

    if (event->is<sf::Event::MouseButtonPressed>()) {
        for (auto& button : buttons) {
            if (button.isMouseOver(window)) {
                button.handleClick();
                if (currentScreen == screen_type::main_screen) {
                    // Find the selected contact
                    for (const auto& contact : contacts) {
                        if (contact.code_name == button.getName()) {
                            currentScreen = contact_screen;
                            createPhoneButtons(contact);
                            break;
                        }
                    }
                } else if (currentScreen == screen_type::contact_screen) {
                    if (button.getType() == Button::ButtonType::BACK) {
                        // Clear buttons first, then change screen and create new buttons
                        buttons.clear();
                        currentScreen = main_screen;
                        createContactButtons();
                    }
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