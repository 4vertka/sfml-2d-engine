// menu_state.hpp
#pragma once
#include "camera.hpp"
#include "state.hpp"
#include "tilemap.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstddef>
#include <memory>
#include <optional>
#include <vector>
#include "menuCamera.hpp"

class MenuState : public States {
public:
    MenuState();

    void handleInput(EngineClass& engine,const sf::Event& event) override;
    void update(EngineClass& engine, float deltaTime) override;
    void render(EngineClass& engine) override;
private:
    sf::Font font;
    //std::optional<std::vector<sf::Text>> texts;
    //std::vector<std::optional<sf::Text>> texts;
    std::vector<std::optional<sf::Text>> texts;
    MenuCamera menuCamera;
};

