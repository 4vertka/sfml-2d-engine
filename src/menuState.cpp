// menu_state.cpp
#include "menuState.hpp"
#include "button.hpp"
#include "engine.hpp"
#include "levelState.hpp" 
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>
#include <memory>
#include <stdexcept>

MenuState::MenuState() {
    if (!font.openFromFile("../textures/apercumovistarbold.ttf")) {
        throw std::runtime_error("failed to load font");
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
}

void MenuState::update(EngineClass& engine, float deltaTime) {

}

void MenuState::render(EngineClass& engine) {
    sf::RenderWindow& window = engine.getWindow();
    window.clear(sf::Color::Black);
    menuCamera.Render(window);
    Button playButton =
        Button(50, 50, 100, 100, font, "aboba", sf::Color::White, sf::Color::White, sf::Color::White);
    playButton.render(window);
    engine.drawImgui();
    window.display();
}


