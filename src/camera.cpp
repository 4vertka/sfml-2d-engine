#include "./camera.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cmath>

Camera::Camera() {
  camera.setCenter({0.0f,0.0f});
  camera.setSize({1920.0f, 1080.0f});
}

void Camera::Render(RenderWindow &window) { window.setView(camera); }

void Camera::Update() {

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
    camera.move(movement * cameraSpeed);
  }
}

void Camera::updateFollow(Entety& object) {
  camera.setCenter(object.getPosition());
}
