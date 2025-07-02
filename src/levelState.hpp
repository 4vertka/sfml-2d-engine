#pragma once 
#include "state.hpp"
#include "player.hpp"
#include "tilemap.hpp"
#include "camera.hpp"

class levelState : public States {
  public:
    void handleInput(EngineClass& engine,const sf::Event& event) override;
    void update(EngineClass& engine, float deltaTime) override;
    void render(EngineClass& engine) override;

    PlayerClass player;
    TileMap map;
    Camera camera;
};
