#pragma once                                         
#include <SFML/Graphics.hpp>                         
                                                     
class MenuCamera                                         
{                                                    
public:                                              
        MenuCamera() {
          menuCamera.setCenter({0.0f, 0.0f});
          menuCamera.setSize({1920.0f, 1080.0f});
        }                                    
        void Render(sf::RenderWindow &window) {
          window.setView(menuCamera);
        }           
        //void Update();                               
        //void updateFollow(Entety& object);           
                                                     
        sf::View menuCamera;                                 
private:                                             
        float cameraSpeed{16.0f};                    
        float cameraZoom{1.0f};                      
};                                                   
                        


                                                                                       
