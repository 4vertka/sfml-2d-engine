#pragma once                                         
#include <SFML/Graphics.hpp>                         
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

class MenuCamera                                         
{                                                    
public:                                              
        MenuCamera() {
          menuCamera.setCenter(menuCamera.getSize() / 2.0f);
          menuCamera.setSize({1920.0f, 1080.0f});
        }                                    
        void Render(sf::RenderWindow &window) {
                window.setView(menuCamera);
        } 

        void Resize(sf::Vector2f newSize) {
                menuCamera.setSize(newSize);
                menuCamera.setCenter(menuCamera.getSize() / 2.0f);
        }
                                                     
        sf::View menuCamera;                                 
private:                                             
        float cameraSpeed{16.0f};                    
        float cameraZoom{1.0f};
};                                                   
                        


                                                                                       
