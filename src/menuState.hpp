// menu_state.hpp
#pragma once
#include "camera.hpp"
#include "state.hpp"
#include "tilemap.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstddef>
#include <map>
#include <memory>
#include <optional>
#include <vector>
#include "menuCamera.hpp"
#include "button.hpp"

class MenuState : public States {
public:
    MenuState();
    ~MenuState();

    void handleInput(EngineClass& engine,const sf::Event& event) override;
    void update(EngineClass& engine, float deltaTime) override;
    void render(EngineClass& engine) override;
    void initButtons();
    void updateButtons(EngineClass& engine, sf::Vector2f mousePos);
    void renderButtons(sf::RenderWindow& window);

    void initBackground();
    void renderBackground(sf::RenderWindow& window);
private:
    sf::Font font;
    MenuCamera menuCamera;
    sf::Texture texture;
    std::map<std::string, Button*> buttons;

    std::optional<sf::Sprite> backgroundSprite;
    sf::Texture backgroundTexture{};
};








