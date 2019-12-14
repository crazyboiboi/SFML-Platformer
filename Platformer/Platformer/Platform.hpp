#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Platform : public Entity {

public:
	Platform(sf::Texture& spritesheet, sf::IntRect intrect, float posX, float posY, sf::Vector2f size);
	~Platform();

	void Draw(sf::RenderWindow& window);
	
private:


};