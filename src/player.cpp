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
#include "player.hpp"

PlayerClass::PlayerClass() : texture("../textures/soldier.png"), sprite(texture) {

  sprite.setTextureRect({{0,0}, {100, 100}});
  sprite.setOrigin({sprite.getTextureRect().size.x / 2.0f, sprite.getTextureRect().size.y / 2.0f});

  position = {100.0f, 100.0f};
  scale = {4.0f, 4.0f};

  sprite.setScale(scale); 
  sprite.setPosition(position);      

}

void PlayerClass::PlayerMainLoop() {

  playerControl();


  timer += 0.05f;
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
}

void PlayerClass::drawPlayer(sf::RenderWindow& window) {
  window.draw(sprite);
}

void PlayerClass::playerControl() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {  
    changeX = -playerSpeed * std::sin(45); 
  }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {         
    changeX = playerSpeed * std::sin(45);
  }else {
    changeX = 0;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
    changeY = -playerSpeed * std::sin(45);
  }else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
    changeY = playerSpeed * std::sin(45);
  }else {
    changeY = 0;
  }             
  sprite.move({changeX, changeY});
}
