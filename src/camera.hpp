#pragma once
#include <SFML/Graphics.hpp>
#include "entety.hpp"


class Camera
{
public:
        Camera();
        void Render(sf::RenderWindow &window);
        void Update();
        void updateFollow(Entety& object);

        sf::View camera;
private:
        float cameraSpeed{16.0f};
        float cameraZoom{1.0f};
};

