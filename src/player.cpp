#include "./player.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
#include <memory>
#include <stdexcept>

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

void PlayerClass::playerControl() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {  
    changeX = -playerSpeed * std::sin(45); 
    playerAnimation(LEFT, 384, 448);
  }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {         
    changeX = playerSpeed * std::sin(45);
    playerAnimation(RIGHT, 384, 384);
  }else {
    changeX = 0;
    //playerAnimation(IDLE, 0, 0);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
    changeY = -playerSpeed * std::sin(45);
    playerAnimation(UP, 384, 320);
  }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
    changeY = playerSpeed * std::sin(45);
    playerAnimation(DOWN, 384, 256);
  }else {
    changeY = 0;
   // playerAnimation(IDLE, 0, 0);
  }             
  sprite.move({changeX, changeY});
}
