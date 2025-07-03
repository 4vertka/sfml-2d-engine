#include "button.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>

Button::Button(float x, float y, float width, float height,
    sf::Font font ,std::string text, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor) {

  this->buttonState = BUTTON_IDLE;

  this->shape.setPosition(sf::Vector2f(-x, -y));
  this->shape.setSize(sf::Vector2f(width, height));
  this->font = font;

  //this->text->setFont(font);
  this->text.emplace(this->font);
  this->text->setFont(this->font);
  this->text->setString(text);
  this->text->setFillColor(sf::Color::Black);
  this->text->setCharacterSize(12);

  this->text->setPosition(sf::Vector2f(
          this->shape.getPosition().x /2.0f - this->text->getGlobalBounds().size.x / 2.0f,
          this->shape.getPosition().y / 2.0f - this->text->getGlobalBounds().size.y / 2.0f
        ));

  this->idleColor = idleColor;
  this->hoverColor = hoverColor;
  this->activeColor = activeColor;

  this->shape.setFillColor(this->idleColor);

}

Button::~Button() {}

const bool Button::isPressed() const {
  if (this->buttonState == BUTTON_ACTIVE) {
    return true;
  }
  return false;
}

void Button::render(sf::RenderWindow& window) {
  window.draw(this->shape);
  window.draw(this->text.value());
}

void Button::update(const sf::Vector2f mousePos) {
  this->buttonState = BUTTON_IDLE;
  if (this->shape.getGlobalBounds().contains(mousePos)) {
    this->buttonState = BUTTON_HOVER;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
      this->buttonState = BUTTON_ACTIVE;
    }
  }

  switch (this->buttonState) {
    case BUTTON_IDLE:
      this->shape.setFillColor(this->idleColor);
      break;

    case BUTTON_HOVER:
      this->shape.setFillColor(this->hoverColor);
      break;

    case BUTTON_ACTIVE:
      this->shape.setFillColor(this->activeColor);
      break;

    default:
      this->shape.setFillColor(sf::Color::Red);
      break;
  }
}
