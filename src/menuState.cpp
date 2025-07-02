// menu_state.cpp
#include "menuState.hpp"
#include "engine.hpp"
#include "levelState.hpp" 
#include "player.hpp"
#include <SFML/Graphics/Font.hpp>
#include <memory>
#include <stdexcept>

MenuState::MenuState(): font("../textures/apercumovistarbold.ttf"), titleText(font) {
    if (!font.openFromFile("../textures/apercumovistarbold.ttf")) {
        throw std::runtime_error("failed to load asset");
    }
    titleText.setFont(font);
    titleText.setString("Menu");
    titleText.setCharacterSize(40);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition({100, 100});
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
}

void MenuState::update(EngineClass& engine, float deltaTime) {
}

void MenuState::render(EngineClass& engine) {
    sf::RenderWindow& window = engine.getWindow();
    window.clear(sf::Color::Black);
    window.draw(titleText);
    window.display();
}

