// menu_state.hpp
#pragma once
#include "camera.hpp"
#include "state.hpp"
#include "tilemap.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include "menuCamera.hpp"

class MenuState : public States {
public:
    MenuState();

    void handleInput(EngineClass& engine,const sf::Event& event) override;
    void update(EngineClass& engine, float deltaTime) override;
    void render(EngineClass& engine) override;
private:
    sf::Font font;
    sf::Text titleText;
    MenuCamera menuCamera;
};

