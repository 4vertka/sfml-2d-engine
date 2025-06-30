#include "./camera.hpp"
#include "player.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

Camera::Camera() {
}

void Camera::Render(RenderWindow &window) { window.setView(camera); }

void Camera::Update() {

}
