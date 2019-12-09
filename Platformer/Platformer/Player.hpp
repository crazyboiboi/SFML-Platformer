#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "Definitions.hpp"
#include "Platform.hpp"

class Player : public Entity {

public:
	Player(std::string imgDirectory, float posX, float posY, sf::Vector2f size);
	~Player();

	void Update(float dt, std::vector<Platform> platforms);

	void UpdatePhysics(float dt);

	void Move(float dt);

	void Jump();
	void ShortJump();

	void Collision(std::vector<Platform> platforms);

	void Draw(sf::RenderWindow& window);


private:
	bool is_grounded;
	bool is_jumping = true;
	bool is_walking;

	bool collideLeft = false;
	bool collideRight = false;
	bool collideBottom = false;

	sf::Vector2f velocity;
	sf::Vector2f acceleration;

};