#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <string>

class PlayerClass {
  public:
    PlayerClass();
    sf::Texture texture{};
    sf::Clock clock{};
    sf::Vector2f position{};
    sf::Vector2f scale{};

    sf::IntRect rectangleSourceSprite{};   


    int texWidth {0};
    float timer{0.0f};
    float timerMax = 0.25f;

    void PlayerMainLoop(sf::Vector2f position, sf::Vector2f scale);
    void drawPlayer(sf::RenderWindow& window);

  private:

    sf::Sprite sprite;
};
