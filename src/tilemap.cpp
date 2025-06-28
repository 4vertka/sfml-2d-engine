#include "tilemap.hpp"
#include <SFML/Graphics/PrimitiveType.hpp>

bool TileMap::load(const std::filesystem::path &tilesets, sf::Vector2u tileSize,
                   const int *tiles, unsigned int width, unsigned int height) {
  if (!tileset.loadFromFile(tilesets)) {
    return false;
  }

  vertexArray.setPrimitiveType(sf::PrimitiveType::Triangles);
  vertexArray.resize(width * height * 6);

  for (unsigned int i = 0; i < width; ++i) {
    for (unsigned int j = 0; j < height; ++j) {
      const int tileNumber = tiles[i + j * width];

      const int tu = tileNumber % (tileset.getSize().x / tileSize.x);
      const int tv = tileNumber / (tileset.getSize().x / tileSize.x);

      sf::Vertex *triangles = &vertexArray[(i + j * width) * 6];

      triangles[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
      triangles[1].position =
          sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
      triangles[2].position =
          sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
      triangles[3].position =
          sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);
      triangles[4].position =
          sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
      triangles[5].position =
          sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);

      triangles[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
      triangles[1].texCoords =
          sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
      triangles[2].texCoords =
          sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
      triangles[3].texCoords =
          sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
      triangles[4].texCoords =
          sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
      triangles[5].texCoords =
          sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
    }
  }
  return true;
}
