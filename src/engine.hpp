#include "mehses.hpp"
#include "tilemap.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/WindowEnums.hpp>
#include <memory>
#include <optional>
#include <utility>
#include "state.hpp"

class EngineClass {
public:
  void initWindow();
  void mainLoop();
  //void draw();
  void createMeshes();
  void createMesh(std::string texturePath, sf::Vector2f position,
                  sf::Vector2f scale);
  void cleanup();
  void drawImgui();

  void changeState(std::unique_ptr<States> newState) {currentState = std::move(newState);}
  sf::RenderWindow& getWindow() {return window;}

  bool cameraMode{false};
protected:
  sf::RenderWindow window;
  sf::Clock deltaClock;
  std::vector<Mesh> meshes;

  std::unique_ptr<States> currentState;
};
