#pragma once

#include <SFML/Graphics.hpp>
#include "Hitbox.hpp"

class Entity : public Hitbox {

public:
	sf::RectangleShape rect;
	sf::Sprite sprite;
	sf::Text text;
	sf::Texture texture;

};