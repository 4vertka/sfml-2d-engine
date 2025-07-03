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
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Clipboard.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <climits>
#include <cstdio>
#include <ctime>
#include <exception>
#include <iostream>
#include <memory>
#include <new>
#include <stdexcept>
#include "../imgui-sfml/imgui-SFML.h"
#include "menuState.hpp"
#include "levelState.hpp"
#include <imgui.h>
#include <string>

void EngineClass::initWindow() {

  window.create(sf::VideoMode({1920, 1080}, sf::Style::Resize), "My window",
                sf::State::Windowed);

  window.setVerticalSyncEnabled(true);
  window.setFramerateLimit(60);


 // createMeshes();

  if (!ImGui::SFML::Init(window)) {
    throw std::runtime_error("failed to load imgui");
  } 

}

void EngineClass::mainLoop() {
  sf::Clock clock;
  while (window.isOpen()) {
    float deltaTime = clock.restart().asSeconds();
    while (const std::optional event = window.pollEvent()) {
      ImGui::SFML::ProcessEvent(window, *event);

      currentState->handleInput(*this, *event);
      
    }
    currentState->update(*this, deltaTime);
    currentState->render(*this);
  }

  cleanup();
}

void EngineClass::createMeshes() {
   createMesh("../textures/soldier.png", {100.0f, 100.0f}, {2.0f, 2.0f});
}

void EngineClass::createMesh(std::string texturePath, sf::Vector2f position,
                             sf::Vector2f scale) {

  Mesh newMesh;

  newMesh.position = position;
  newMesh.scale = scale;
  newMesh.initPrimitives(texturePath);

  meshes.push_back(newMesh);
}

void EngineClass::cleanup() {
  ImGui::SFML::Shutdown();
}

void EngineClass::drawImgui() {
  ImGui::SFML::Update(window, deltaClock.restart());                
                                                                    
  ImGui::Begin("Hello world");       
  if (ImGui::Button("playerMode")) {
    cameraMode = false;
  }else if (ImGui::Button("cameraMode")) {
    cameraMode = true;
  }else if (ImGui::Button("menu state")) {
   changeState(std::make_unique<MenuState>());
  }else if (ImGui::Button("level state")) {
    changeState(std::make_unique<levelState>());
  }

  ImGui::End();  
  ImGui::SFML::Render(window);                                     
}

