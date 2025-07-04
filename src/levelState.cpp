#include "levelState.hpp"
#include "levelState.hpp"
#include "engine.hpp"
#include "menuState.hpp"
#include <SFML/System/Vector2.hpp>
#include <memory>

void levelState::handleInput(EngineClass& engine,const sf::Event& event) {
  if (event.is<sf::Event::Closed>()) {             
    engine.getWindow().close();                                 
  }
  else if (const auto *keyPressed = event.getIf<sf::Event::KeyPressed>()) {                   
    if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {                              
      engine.getWindow().close();                                                                          
    } 
    if (keyPressed->scancode == sf::Keyboard::Scancode::Enter) {                        
      engine.changeState(std::make_unique<MenuState>());
    }                                                                                    
  }                                                                                            
  if (const auto *resized = event.getIf<sf::Event::Resized>()) {                              
    camera.resize(sf::Vector2f(resized->size.x, resized->size.y));
  }
}

void levelState::update(EngineClass& engine, float deltaTime) {
  camera.initCamera(engine.getWindow());
  if (engine.cameraMode) camera.Update();
  else {player.update();camera.updateFollow(player);}
}

void levelState::render(EngineClass& engine) {
  engine.getWindow().clear(sf::Color::White);
  camera.Render(engine.getWindow());                                         
  engine.getWindow().draw(map.vertexArray, &map.tileset);                    
  //for (auto &mesh : meshes) {                                    
                                                                 
  //sf::RenderStates states;                                     
  //states.texture = &mesh.texture;                              
  //states.transform = mesh.transform;                           
  //window.draw(mesh.vertexArray, states);                       
  //}                                                              
                                                                 
  map.createTileMap();                                           
  player.draw(engine.getWindow());                                           
                                                                 
  engine.drawImgui();

  engine.getWindow().display();
}
