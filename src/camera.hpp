#include "player.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

class Camera
{
public:
        Camera();
        void Render(RenderWindow &window);
        void Update();
private:
        View camera;
};

