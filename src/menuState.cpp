// menu_state.cpp
#include "menuState.hpp"
#include "engine.hpp"
#include "levelState.hpp" 
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <memory>
#include <stdexcept>

MenuState::MenuState(): font("../textures/apercumovistarbold.ttf"), titleText(font) {
    if (!font.openFromFile("../textures/apercumovistarbold.ttf")) {
        throw std::runtime_error("failed to load font");
    }
    titleText.setFont(font);
    titleText.setString("Menu");
    titleText.setCharacterSize(40);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition({0, 0});

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
    menuCamera.Render(window);
    window.draw(titleText);
    engine.drawImgui();
    window.display();
}


