#include <SFML/Graphics.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Main.hpp>
#include <SFML/System/Vector2.hpp>

class Mesh {
public:
  sf::Texture texture{};
  sf::Vector2f position{};
  sf::Vector2f scale{};
  sf::VertexArray vertexArray{};

  void initPrimitives() {
    vertexArray.setPrimitiveType(sf::PrimitiveType::TriangleStrip);
    vertexArray.resize(4);

    sf::Vector2u textureSize = texture.getSize();
    float width = static_cast<float>(textureSize.x) * scale.x;
    float height = static_cast<float>(textureSize.y) * scale.y;

    vertexArray[0].position = sf::Vector2f(position.x, position.y);
    vertexArray[1].position = sf::Vector2f(position.x, position.y + height);
    vertexArray[2].position = sf::Vector2f(position.x + width, position.y);
    vertexArray[3].position =
        sf::Vector2f(position.x + width, position.y + height);

    vertexArray[0].texCoords = sf::Vector2f(0.f, 0.f);
    vertexArray[1].texCoords =
        sf::Vector2f(0.f, static_cast<float>(textureSize.y));
    vertexArray[2].texCoords =
        sf::Vector2f(static_cast<float>(textureSize.x), 0.f);
    vertexArray[3].texCoords = sf::Vector2f(static_cast<float>(textureSize.x),
                                            static_cast<float>(textureSize.y));
  }
};
