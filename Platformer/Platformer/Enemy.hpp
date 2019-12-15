#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "DEFINITIONS.hpp"

class Enemy : public Entity {
	
public:
	Enemy(sf::Texture& spritesheet, float posX, float posY, bool going_left, sf::Vector2f size);
	~Enemy();

	void Update(float dt);
	void Draw(sf::RenderWindow& window);

	bool outOfFrame();

private:
	sf::Vector2f velocity;
	sf::Vector2f position;

	bool _outOfFrame = false;
};