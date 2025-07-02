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

void PlayerClass::playerAnimation(int maxTexturePixel, int texPositionDown) {
  timer += 0.05f;                                                      
  if (timer >= timerMax) {                                             
    texWidth += 64;                                                    
                                                                     
    if (texWidth >= maxTexturePixel) {                              
      texWidth = 0;                                                    
    }                                                                  
                                                                     
    if (texWidth < texture.getSize().x) {                              
      setTextureRect({{texWidth, texPositionDown}, {64, 64}});
    }                                                                  
                                                                     
    timer = 0.0f;                                                      
}
}

void PlayerClass::update()   {
  sf::Vector2f movement(0,0);                                                         
                                                                                             
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
    move(movement * playerSpeed);
                                                                                             
    if (left)       playerAnimation(384, 448);                                              
    else if (right) playerAnimation(384, 384);                                              
    else if (up)    playerAnimation(384, 320);                                              
    else if (down)  playerAnimation(384, 256);        
  }                                                                                          
}
