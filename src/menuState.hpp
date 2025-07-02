// menu_state.hpp
#pragma once
#include "state.hpp"
#include <SFML/Graphics.hpp>

class MenuState : public States {
public:
    MenuState();

    void handleInput(EngineClass& engine,const sf::Event& event) override;
    void update(EngineClass& engine, float deltaTime) override;
    void render(EngineClass& engine) override;

private:
    sf::Font font;
    sf::Text titleText;
};

