#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include "entety.hpp"


class Camera
{
public:
        Camera() = default;
        void Render(sf::RenderWindow &window);
        void Update();
        void updateFollow(Entety& object);
        void resize(sf::Vector2f newSize);
        void initCamera(sf::RenderWindow& window);

        sf::View camera;
private:
        float cameraSpeed{16.0f};
};

