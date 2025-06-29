#include "./player.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <memory>
#include <stdexcept>

#include "player.hpp"
#include "player.hpp"

PlayerClass::PlayerClass() : texture("../textures/soldier.png"), sprite(texture) {

  rectangleSourceSprite.position = {0, 0};                  
  rectangleSourceSprite.size = {100, 100};       

  sprite.setTextureRect({{0,0}, {100, 100}});
  sprite.setOrigin({sprite.getTextureRect().size.x / 2.0f, sprite.getTextureRect().size.y / 2.0f});

}

void PlayerClass::PlayerMainLoop(sf::Vector2f position, sf::Vector2f scale) {

  sprite.setPosition(position);      
  sprite.setScale(scale); 

  timer += 0.1f;
  if (timer >= timerMax) {
    texWidth += 100;

    if (texWidth >= texture.getSize().x) {
      texWidth = 0;
    }

    if (texWidth < texture.getSize().x) {
      sprite.setTextureRect({{texWidth, 0}, {100, 100}});
    }

    timer = 0.0f;
  }
    
  if (clock.getElapsedTime().asSeconds() > 1.0f) {
    if (rectangleSourceSprite.position == sf::Vector2{500, 0}) {
      rectangleSourceSprite.position = sf::Vector2{100, 0};
    }else {
      rectangleSourceSprite.position += sf::Vector2{100, 0};
    }
    sprite.setTextureRect(rectangleSourceSprite);
    clock.reset();
  }
}

void PlayerClass::drawPlayer(sf::RenderWindow& window) {
  window.draw(sprite);
}
