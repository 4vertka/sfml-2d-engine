#include "engine.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <climits>
#include <exception>
#include <iostream>
#include <new>
#include <stdexcept>

void EngineClass::initWindow() {

  window.create(sf::VideoMode({1920, 1080}, sf::Style::Resize), "My window",
                sf::State::Windowed);

  window.setVerticalSyncEnabled(true);
  window.setFramerateLimit(60);


  createTileMap();

  createMeshes();
}

void EngineClass::mainLoop() {

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {

      if (event->is<sf::Event::Closed>()) {
        window.close();
      }
      else if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>()) {
        if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
          window.close();
        }
      }
      if (const auto *resized = event->getIf<sf::Event::Resized>()) {
        window.setSize({resized->size.x, resized->size.y});
      }
    }
    draw();
  }
}

void EngineClass::draw() {
  window.clear(sf::Color::White);

  window.draw(map.vertexArray, &map.tileset);

  for (auto &mesh : meshes) {
    window.draw(mesh.vertexArray, &mesh.texture);
  }
  window.display();
}

void EngineClass::createMeshes() {
  // createMesh("../textures/forest-2.png", {10.0f, 50.0f}, {0.5f, 0.5f});
  // createMesh("../textures/forest-2.png", {100.0f, 100.0f}, {1.0f, 1.0f});
}

void EngineClass::createMesh(std::string texturePath, sf::Vector2f position,
                             sf::Vector2f scale) {

  Mesh newMesh;

  if (!newMesh.texture.loadFromFile(texturePath)) {
    throw std::runtime_error("failed to load texture: " + texturePath);
  }
  newMesh.position = position;
  newMesh.scale = scale;

  newMesh.initPrimitives();

  meshes.push_back(newMesh);
}

void EngineClass::createTileMap() {

  std::vector<int> level = {
    8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10,
    16,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,18,
    16,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,18,
    16,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,18,
    16,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,18, 
    16,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,18, 
    16,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,18, 
    16,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,18, 
    16,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,18, 
    16,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,18, 
    16,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,18, 
    16,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,18, 
    16,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,18, 
    16,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,18,
    16,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,17,18, 
    24,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,25,26
    };

  if (!map.load("../textures/tileset_1bit.png", {16, 16}, level.data(), 28, 16)) {
    throw std::runtime_error("failed to load tilemap");
  }
}
