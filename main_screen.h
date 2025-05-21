#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "button.h"
#include <stdlib.h>
#include <nlohmann/json.hpp>
#include <fstream>

struct Contact {
    std::string name;
    std::string address;
    std::string primary;
    std::string secondary;
    std::string tertiary;
    std::string local_police;
    std::string code_name;
};

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
    std::vector<Contact> contacts;
    
    void loadContacts();
    void createContactButtons();
}; 