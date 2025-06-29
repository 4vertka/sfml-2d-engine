#include "gameMenu.h"
#include <stdexcept>

void GameMenu::setInitText(sf::Text& text, sf::String str, float xpos, float ypos) {
  text.setFont(font);
  text.setFillColor(menu_text_color);
  text.setString(str);
  text.setCharacterSize(size_font);
  text.setPosition({xpos, ypos});
  text.setOutlineThickness(3);
  text.setOutlineColor(border_color);
}

void GameMenu::AlignMenu(int posx)  {
  float nullx = 0;
  for (int i = 0; i < max_menu; i++) {
    switch (posx) {
      case 0:
        nullx = 0;
        break;
      case 1:
        nullx = mainMenu[i].getLocalBounds().size.x;
        break;
      case 2:
        nullx = mainMenu[i].getLocalBounds().size.x / 2;
        break;
    }
    mainMenu[i].setPosition({mainMenu[i].getPosition().x, mainMenu[i].getPosition().y});
  }
}


GameMenu::GameMenu(sf::RenderWindow& window, float menux, float menuy, int index, sf::String name[], int sizeFont, int step)
: myWindow(window), menu_x(menux), menu_y(menuy), size_font(sizeFont), menu_Step(step)
{

 if (!font.openFromFile("")) throw std::runtime_error("failed to load fonts");

}
