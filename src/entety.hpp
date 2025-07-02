#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <stdexcept>
#include <string>


class Entety {
protected:
    sf::Vector2f position{};       
    sf::Vector2f velocity;       
    sf::Texture texture;         
    sf::Vector2f scale{4.0f, 4.0f};          

    sf::Sprite sprite;
    
public:
    Entety(): texture("../textures/char_a_p1_0bas_humn_v00.png"), sprite(texture) {
        sprite.setTextureRect({{0, 0}, {64, 64}});
        sprite.setScale(scale);
    }

    virtual void update() = 0;
    
    virtual void draw(sf::RenderWindow& window) {this->sprite.setPosition(position); window.draw(sprite);};

    void setPosition(const sf::Vector2f& pos) { this->position = pos;}
    void setTextureRect(const sf::IntRect& rectangle) {this->sprite.setTextureRect(rectangle);}
    sf::Vector2f getPosition() const {return this->position;}

    void move(const sf::Vector2f& deltatime) {this->position += deltatime;}

    sf::FloatRect getBounds() const {return this->sprite.getGlobalBounds();}
};
