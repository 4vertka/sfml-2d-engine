#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Window/WindowEnums.hpp>
#include <optional>

class EngineClass {
public:
  void initWindow();
  void mainLoop();
  void draw();
  sf::Sprite createTexture();

private:
  sf::RenderWindow window;
  sf::Texture texture;
};
