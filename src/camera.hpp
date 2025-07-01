#pragma once
#include <SFML/Graphics.hpp>
#include "entety.hpp"

using namespace sf;

class Camera
{
public:
        Camera();
        void Render(RenderWindow &window);
        void Update();
        void updateFollow(Entety& object);
private:
        View camera;
        float cameraSpeed{16.0f};
        float cameraZoom{1.0f};
};

