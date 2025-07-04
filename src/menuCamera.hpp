#pragma once                                         
#include <SFML/Graphics.hpp>                         
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

class MenuCamera                                         
{                                                    
public:                                              
        MenuCamera() = default;

        void initMenuCamera(sf::RenderWindow& window) {
                sf::Vector2f viewSize(sf::Vector2f(window.getSize().x, window.getSize().y));      
                menuCamera.setSize(viewSize);                                                     
                menuCamera.setCenter(viewSize * 0.5f);                                            
        }

        void Render(sf::RenderWindow &window) {
                window.setView(menuCamera);
        } 

        void Resize(sf::Vector2f newSize) {
                menuCamera.setSize(newSize);
                menuCamera.setCenter(menuCamera.getSize() / 2.0f);
        }
                                                     
        sf::View menuCamera;                       

};                                                   
                        


                                                                                       
