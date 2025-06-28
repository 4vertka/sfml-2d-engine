#include "engine.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <exception>
#include <iostream>
#include <stdexcept>

void EngineClass::initWindow() {

  window.create(sf::VideoMode({800, 600}, sf::Style::Resize), "My window",
                sf::State::Windowed);

  window.setVerticalSyncEnabled(true);
  window.setFramerateLimit(60);

  createTexture();
}

void EngineClass::mainLoop() {

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {

      if (event->is<sf::Event::Closed>()) {
        window.close();
      } else if (const auto *keyPressed =
                     event->getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
          window.close();
        }
      }
      if (const auto *resized = event->getIf<sf::Event::Resized>()) {
        std::cout << "new width " << resized->size.x << std::endl;
        std::cout << "new height " << resized->size.y << std::endl;
      }
    }
    draw();
  }
}

void EngineClass::draw() {
  window.clear(sf::Color::Blue);
  window.draw(createTexture());
  window.display();
}

sf::Sprite EngineClass::createTexture() {
  if (!texture.loadFromFile("../textures/forest-2.png")) {
    throw std::runtime_error("failed to load texture");
  }
  texture.setSmooth(true);
  sf::Sprite sprite(texture);

  return sprite;
}
