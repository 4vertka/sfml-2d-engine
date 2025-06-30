#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <filesystem>

class TileMap {
public:
  sf::Texture tileset;
  sf::VertexArray vertexArray{};

  bool load(const std::filesystem::path &tilesets, sf::Vector2u tileSize,
            const int *tiles, unsigned int width, unsigned int height);

  void createTileMap();                                                                    
};
