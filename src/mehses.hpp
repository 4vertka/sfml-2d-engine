#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Main.hpp>
#include <SFML/System/Vector2.hpp>

class Mesh {
public:
  sf::Texture texture{};
  sf::Vector2f position{0.0f, 0.0f};
  sf::Vector2f scale{0.5f, 2.0f};
};
