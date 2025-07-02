#include "./camera.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cmath>

Camera::Camera() {
  camera.setCenter({500.0f,500.0f});
  camera.setSize({1920.0f, 1080.0f});
}

void Camera::Render(sf::RenderWindow &window) { window.setView(camera); }

void Camera::Update() {
  
  sf::Vector2f movement{};
                                                                                                
  bool left = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);                                 
  bool right = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D);                                
  bool up = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W);                                   
  bool down = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S);  
  bool zoomUp = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E);
  bool zoomDown = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q);
                                                                                                
  if (left) movement.x -= 1.0f;                                                                 
  if (right) movement.x += 1.0f;                                                                
  if (up) movement.y -= 1.0f;                                                                   
  if (down) movement.y += 1.0f;       
  if (zoomUp) camera.zoom(1.01f);
  if (zoomDown) camera.zoom(0.99f);

  
  if (movement.x != 0.0f || movement.y != 0.0f) {                                               
    float length = std::sqrt(movement.x * movement.x + movement.y * movement.y);                
    movement /= length;               
    camera.move(movement * cameraSpeed);
  }
}

void Camera::updateFollow(Entety& object) {
  camera.setCenter({object.getPosition().x + 128, object.getPosition().y });
}

