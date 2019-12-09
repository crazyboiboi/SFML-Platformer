#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class Platform : public Entity {

public:
	Platform(std::string imgDirectory, float posX, float posY, sf::Vector2f size);
	~Platform();

	void Draw(sf::RenderWindow& window);
	
private:


};