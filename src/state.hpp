#pragma once
#include <SFML/Graphics.hpp>

class EngineClass; 

class States {
public:
    virtual ~States() = default;

    virtual void handleInput(EngineClass& engine, const sf::Event& event) = 0;
    virtual void update(EngineClass& engine, float deltaTime) = 0;
    virtual void render(EngineClass& engine) = 0;
};

