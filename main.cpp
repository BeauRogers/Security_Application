#include <SFML/Graphics.hpp>
#include <iostream>

// Button class to handle interaction
class Button {
public:
    Button(float x, float y, float width, float height, const sf::Color& color, const std::string& buttonName) 
        : name(buttonName) {
        shape.setSize(sf::Vector2f(width, height));
        shape.setPosition(sf::Vector2f(x, y));
        shape.setFillColor(color);
        originalColor = color;
    }

    void draw(sf::RenderWindow& window) {
        window.draw(shape);
    }

    bool isMouseOver(const sf::RenderWindow& window) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosFloat(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
        return shape.getGlobalBounds().contains(mousePosFloat);
    }

    void handleHover(const sf::RenderWindow& window) {
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

    void handleClick() {
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

private:
    sf::RectangleShape shape;
    sf::Color originalColor;
    std::string name;
};

int main()
{
    // Create a window
    sf::RenderWindow window(sf::VideoMode({600, 600}), "SFML proof of concept");
    
    // State tracking
    bool showMainScreen = false;
    
    // Create the enter button (centered)
    const float enterButtonWidth = 200;
    const float enterButtonHeight = 80;
    Button enterButton(
        (600 - enterButtonWidth) / 2,  // x position (centered)
        (600 - enterButtonHeight) / 2, // y position (centered)
        enterButtonWidth,
        enterButtonHeight,
        sf::Color(100, 100, 100),     // Gray color
        "Enter"
    );

    // Calculate spacing and positioning for main screen buttons
    const int numButtons = 4;
    const float windowWidth = 600.0f;
    const float buttonWidth = windowWidth * 0.75f;
    const float buttonHeight = 80;
    const float totalButtonsHeight = numButtons * buttonHeight;
    const float verticalSpacing = (600 - totalButtonsHeight) / (numButtons + 1);
    const float xPosition = (windowWidth - buttonWidth) / 2;
    
    // Create main screen buttons
    Button redButton(xPosition, verticalSpacing, 
                    buttonWidth, buttonHeight, sf::Color::Red, "Red Button");
    Button greenButton(xPosition, verticalSpacing * 2 + buttonHeight, 
                      buttonWidth, buttonHeight, sf::Color::Green, "Green Button");
    Button blueButton(xPosition, verticalSpacing * 3 + buttonHeight * 2, 
                     buttonWidth, buttonHeight, sf::Color::Blue, "Blue Button");
    Button yellowButton(xPosition, verticalSpacing * 4 + buttonHeight * 3, 
                       buttonWidth, buttonHeight, sf::Color::Yellow, "Yellow Button");

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            
            // Handle mouse clicks
            if (event->is<sf::Event::MouseButtonPressed>())
            {
                if (!showMainScreen) {
                    if (enterButton.isMouseOver(window)) {
                        enterButton.handleClick();
                        showMainScreen = true;
                    }
                } else {
                    if (redButton.isMouseOver(window)) redButton.handleClick();
                    if (greenButton.isMouseOver(window)) greenButton.handleClick();
                    if (blueButton.isMouseOver(window)) blueButton.handleClick();
                    if (yellowButton.isMouseOver(window)) yellowButton.handleClick();
                }
            }
        }

        window.clear();

        if (!showMainScreen) {
            // Draw enter button
            enterButton.handleHover(window);
            enterButton.draw(window);
        } else {
            // Draw main screen buttons
            redButton.handleHover(window);
            greenButton.handleHover(window);
            blueButton.handleHover(window);
            yellowButton.handleHover(window);
            
            redButton.draw(window);
            greenButton.draw(window);
            blueButton.draw(window);
            yellowButton.draw(window);
        }
        
        window.display();
    }
}