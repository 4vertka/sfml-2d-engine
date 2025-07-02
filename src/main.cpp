#include "engine.hpp"
#include "levelState.hpp"
#include <memory>

int main() {

  EngineClass engine;
  engine.initWindow();
  engine.changeState(std::make_unique<levelState>());
  engine.mainLoop();
  engine.cleanup();

  return 0;
}
