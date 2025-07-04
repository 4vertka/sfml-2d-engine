// menu_state.cpp
#include "menuState.hpp"
#include "button.hpp"
#include "engine.hpp"
#include "levelState.hpp" 
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include <algorithm>
#include <memory>
#include <stdexcept>

MenuState::MenuState() {
    if (!font.openFromFile("../textures/apercumovistarbold.ttf")) {
        throw std::runtime_error("failed to load font");
    }
    this->initButtons();
    this->initBackground();

}

MenuState::~MenuState() {
    for (auto it = this->buttons.begin(); it != buttons.end(); ++it) {
        delete it->second;
    }
}

void MenuState::handleInput(EngineClass& engine,const  sf::Event& event) {
    if (event.is<sf::Event::Closed>()) {                  
      engine.getWindow().close();                         
    }                                                
    else if (const auto *keyPressed = event.getIf<sf::Event::KeyPressed>()) {      
      if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {            
        engine.getWindow().close();                   
      }                                                                       
      if (keyPressed->scancode == sf::Keyboard::Scancode::Enter) {                       
        engine.changeState(std::make_unique<levelState>());                                                       
      }
    }               
    else if (const auto* resized = event.getIf<sf::Event::Resized>()) {
        menuCamera.Resize(sf::Vector2f(resized->size.x, resized->size.y));                                        
    }
}

void MenuState::update(EngineClass& engine, float deltaTime) {
    const sf::Vector2i mousePixelPos = sf::Mouse::getPosition(engine.getWindow());
    sf::Vector2f mousePos = engine.getWindow().mapPixelToCoords(mousePixelPos);
    this->updateButtons(engine, mousePos);
}

void MenuState::render(EngineClass& engine) {
    sf::RenderWindow& window = engine.getWindow();

    window.clear(sf::Color::Black);

    renderBackground(window);
    menuCamera.Render(window);
    this->renderButtons(window);
    engine.drawImgui();

    window.display();
}

void MenuState::initButtons() {
    this->buttons["PLAY"] = new Button(-150, 0, 300, 100, font, "Play", sf::Color::White, sf::Color::Blue, sf::Color::Green);
    this->buttons["EXIT"] = new Button(-150, 200, 300, 100, font, "Exit", sf::Color::White, sf::Color::Blue, sf::Color::Green);
}

void MenuState::updateButtons(EngineClass& engine,sf::Vector2f mousePos) {
    for (auto& button: this->buttons) {
        button.second->update(mousePos);
    }

    if (this->buttons["PLAY"]->isPressed()) {                        
        engine.changeState(std::make_unique<levelState>());          
    }                                                                
    else if (this->buttons["EXIT"]->isPressed()) {                   
        engine.getWindow().close();                                  
   }
}

void MenuState::renderButtons(sf::RenderWindow& window) {
    for (auto& button: this->buttons) {                 
        button.second->render(window);                
    }
}

void MenuState::initBackground() {
    if (!backgroundTexture.loadFromFile("../textures/pixel_art_bg.jpg")) {
        throw std::runtime_error("failed to load texture");
    }

    this->backgroundSprite.emplace(backgroundTexture);
    this->backgroundSprite->setScale({0.1f, 0.1f});
}

void MenuState::renderBackground(sf::RenderWindow& window) {
    window.draw(this->backgroundSprite.value());
}
