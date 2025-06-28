#include "mehses.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/WindowEnums.hpp>
#include <optional>

class EngineClass {
public:
  void initWindow();
  void mainLoop();
  void draw();
  void createMeshes();
  // sf::Sprite drawMesh(Mesh &mesh);
  void createMesh(std::string texturePath, sf::Vector2f position,
                  sf::Vector2f scale);

private:
  sf::RenderWindow window;
  std::vector<Mesh> meshes;
};
