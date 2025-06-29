#include <SFML/Graphics.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Transform.hpp>
#include <SFML/Main.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/System/Vector2.hpp>
#include <stdexcept>
#include <iostream>

class Mesh {
public:
  sf::Texture texture{};
  sf::Transform transform{};
  sf::Vector2f position{};
  sf::Vector2f scale{};
  sf::VertexArray vertexArray{};


  void initPrimitives(std::string texturePath) {
  
    if (!texture.loadFromFile(texturePath)) {                                                
      throw std::runtime_error("failed to load texture for mesh" + texturePath);             
    } 

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
    transform.rotate(sf::degrees(45));
  }
};
