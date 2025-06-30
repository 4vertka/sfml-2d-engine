#include "./player.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
#include <memory>
#include <stdexcept>
#include <utility>

#include "player.hpp"

PlayerClass::PlayerClass() : texture("../textures/char_a_p1_0bas_humn_v00.png"), sprite(texture) {

  sprite.setTextureRect({{0,0}, {64, 64}});
  sprite.setOrigin({sprite.getTextureRect().size.x / 2.0f, sprite.getTextureRect().size.y / 2.0f});

  position = {100.0f, 100.0f};
  scale = {4.0f, 4.0f};

  sprite.setScale(scale); 
  sprite.setPosition(position);      

}

void PlayerClass::PlayerMainLoop() {

  playerControl();
}

void PlayerClass::playerAnimation(PlayerDirection direction, int maxTexturePixel, int texPositionDown) {
  timer += 0.05f;                                                      
  if (timer >= timerMax) {                                             
    texWidth += 64;                                                    
                                                                     
    if (texWidth >= maxTexturePixel) { //texture.getSize().x) {                             
      texWidth = 0;                                                    
    }                                                                  
                                                                     
    if (texWidth < texture.getSize().x) {                              
      sprite.setTextureRect({{texWidth, texPositionDown}, {64, 64}});                
    }                                                                  
                                                                     
    timer = 0.0f;                                                      
}
}

void PlayerClass::drawPlayer(sf::RenderWindow& window) {
  window.draw(sprite);
}

void PlayerClass::movePlayer(PlayerDirection direction) {

}

void PlayerClass::playerControl() {
  sf::Vector2f movement(0.0f, 0.0f);

  bool left = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);
  bool right = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);
  bool up = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);
  bool down = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);

  if (left) movement.x -= 1.0f;
  if (right) movement.x += 1.0f;
  if (up) movement.y -= 1.0f;
  if (down) movement.y += 1.0f;

  if (movement.x != 0.0f || movement.y != 0.0f) {
    float length = std::sqrt(movement.x * movement.x + movement.y * movement.y);
    movement /= length;
    sprite.move(movement * playerSpeed);

    if (left)       playerAnimation(LEFT, 384, 448);
    else if (right) playerAnimation(RIGHT, 384, 384);
    else if (up)    playerAnimation(UP, 384, 320);
    else if (down)  playerAnimation(DOWN, 384, 256);
  }
}
