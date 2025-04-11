#include <SFML/Graphics.hpp>

int main()
{
    // Create a window 3 times bigger (600x600 instead of 200x200)
    sf::RenderWindow window(sf::VideoMode({600, 600}), "SFML proof of concept");
    
    // Calculate spacing and positioning
    const int numButtons = 4;
    const float windowWidth = 600.0f;
    const float buttonWidth = windowWidth * 0.75f; // 75% of window width
    const float buttonHeight = 80;
    const float totalButtonsHeight = numButtons * buttonHeight;
    const float verticalSpacing = (600 - totalButtonsHeight) / (numButtons + 1);
    const float xPosition = (windowWidth - buttonWidth) / 2; // Center horizontally
    
    // Create 4 rectangles of different shapes
    sf::RectangleShape rect1(sf::Vector2f(buttonWidth, buttonHeight));
    rect1.setPosition(sf::Vector2f(xPosition, verticalSpacing));
    rect1.setFillColor(sf::Color::Red);
    
    sf::RectangleShape rect2(sf::Vector2f(buttonWidth, buttonHeight));
    rect2.setPosition(sf::Vector2f(xPosition, verticalSpacing * 2 + buttonHeight));
    rect2.setFillColor(sf::Color::Green);
    
    sf::RectangleShape rect3(sf::Vector2f(buttonWidth, buttonHeight));
    rect3.setPosition(sf::Vector2f(xPosition, verticalSpacing * 3 + buttonHeight * 2));
    rect3.setFillColor(sf::Color::Blue);
    
    sf::RectangleShape rect4(sf::Vector2f(buttonWidth, buttonHeight));
    rect4.setPosition(sf::Vector2f(xPosition, verticalSpacing * 4 + buttonHeight * 3));
    rect4.setFillColor(sf::Color::Yellow);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        
        // Draw all rectangles
        window.draw(rect1);
        window.draw(rect2);
        window.draw(rect3);
        window.draw(rect4);
        
        window.display();
    }
}