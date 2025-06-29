#pragma once
#include <SFML/Graphics.hpp>

class GameMenu {
private:
  float menu_x;
  float menu_y;
  int menu_Step;
  int max_menu;
  int size_font;
  int mainMenuSelected;
  sf::Font font;

  sf::Text* mainMenu;
  sf::Color menu_text_color = sf::Color::White; //пункти меню колір 
  sf::Color chose_text_color = sf::Color::Yellow;
  sf::Color border_color = sf::Color::Black;


  void setInitText(sf::Text& text, sf::String str, float xpos, float ypos);
  sf::RenderWindow& myWindow;

public:

  GameMenu(sf::RenderWindow& window, float menux, float menuy, int index, sf::String name[], int sizeFont = 60, int step = 80);
  ~GameMenu() {
    delete[] mainMenu;
  }

  void draw();
  void moveUp();
  void MoveDown();

  void setColorTextMenu(sf::Color menColor, sf::Color choColor, sf::Color bordColor);

  void AlignMenu(int posx);

  int getSelectedMenuNumber() {
    return mainMenuSelected;
  }
};
