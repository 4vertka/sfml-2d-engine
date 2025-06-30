#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include "entety.hpp"

class PlayerClass : public Entety {
  public:
    float speed = 6.0f;
    //PlayerClass(const std::string& texturePath) {
    //    loadTexture(texturePath);
    //}

    float playerSpeed{6.0f};

    int texWidth {0};
    float timer{0.0f};
    float timerMax = 0.25f;

    void update() override;
    void playerAnimation(int maxTexturePixel, int texPositionDown);

};
