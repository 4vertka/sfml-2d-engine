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
#include <cstdio>
#include <ctime>
#include <exception>
#include <iostream>
#include <new>
#include <stdexcept>
#include "../imgui-sfml/imgui-SFML.h"
#include "player.hpp"
#include <imgui.h>

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
  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      ImGui::SFML::ProcessEvent(window, *event);

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
    player.PlayerMainLoop();
    
    draw();
  }

  cleanup();
}

void EngineClass::draw() {
  window.clear(sf::Color::White);
  window.draw(map.vertexArray, &map.tileset);
  //for (auto &mesh : meshes) {

    //sf::RenderStates states;
    //states.texture = &mesh.texture;
    //states.transform = mesh.transform;
    //window.draw(mesh.vertexArray, states);
  //}
  
  map.createTileMap();
  player.drawPlayer(window);

  drawImgui();
  window.display();
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

  ImGui::Columns(4, NULL);
  ImGui::Separator();

  for(int i= 0; i < 16; i++) {
    ImGui::PushID(i);
    if (i > 0 && i%4 == 0) ImGui::Separator();
    ImGui::Button("aboba", ImVec2(100, 100));
    ImGui::NextColumn();
    ImGui::PopID();
  }
  ImGui::Columns(1);
  ImGui::Separator();
   
  ImGui::End();  
  ImGui::SFML::Render(window);                                     
}
