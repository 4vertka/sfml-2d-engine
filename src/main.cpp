#include "engine.hpp"
#include "menuState.hpp"
#include <memory>

int main() {

  EngineClass engine;
  engine.initWindow();
  engine.changeState(std::make_unique<MenuState>());
  engine.mainLoop();
  engine.cleanup();

  return 0;
}
