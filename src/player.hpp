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
    enum PlayerDirection{IDLE, UP, DOWN , LEFT, RIGHT};
    PlayerClass();
    sf::Texture texture{};
    sf::Vector2f position{};
    sf::Vector2f scale{};
    float playerSpeed{6.0f};

    int texWidth {0};
    float timer{0.0f};
    float timerMax = 0.25f;

    void PlayerMainLoop();
    void drawPlayer(sf::RenderWindow& window);
    void playerControl();
    void playerAnimation(PlayerDirection direction, int maxTexturePixel, int texPositionDown);
    void movePlayer(PlayerDirection direction);

  private:
    sf::Sprite sprite;
};
