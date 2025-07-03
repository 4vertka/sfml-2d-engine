#pragma once 

#include "SFML/Graphics.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <optional>

class Button {
  public:
    Button(float x, float y, float width, float height,                                                           
        sf::Font font ,std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);       
                                                                                                                  
    ~Button();                                                                                                    

    sf::RectangleShape shape;
    sf::Font font;
    std::optional<sf::Text> text;
    //sf::Text* text;
    //sf::Text text;

    sf::Color idleColor;
    sf::Color hoverColor;
    sf::Color activeColor;
    
    void render(sf::RenderWindow& window);

  private: 

      void update(const sf::Vector2f mousePos);

};


