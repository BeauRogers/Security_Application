#include <SFML/Graphics.hpp>

int main()
{
    // Create a window 3 times bigger (600x600 instead of 200x200)
    sf::RenderWindow window(sf::VideoMode({600, 600}), "SFML proof of concept");
    
    // Create 4 rectangles of different shapes
    sf::RectangleShape rect1(sf::Vector2f(100, 100));  // Square
    //sf::Vector2f position1(50, 50);
    rect1.setPosition(sf::Vector2f(50, 50));
    rect1.setFillColor(sf::Color::Red);
    
    sf::RectangleShape rect2(sf::Vector2f(150, 80));   // Wide rectangle
    rect2.setPosition(sf::Vector2f(200, 50));
    rect2.setFillColor(sf::Color::Green);
    
    sf::RectangleShape rect3(sf::Vector2f(80, 150));   // Tall rectangle
    rect3.setPosition(sf::Vector2f(50, 200));
    rect3.setFillColor(sf::Color::Blue);
    
    sf::RectangleShape rect4(sf::Vector2f(120, 120));  // Square
    rect4.setPosition(sf::Vector2f(400, 400));
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