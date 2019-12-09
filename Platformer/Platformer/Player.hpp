#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "Definitions.hpp"
#include "Platform.hpp"

class Player : public Entity {

public:
	Player(std::string imgDirectory, float posX, float posY, sf::Vector2f size);
	~Player();

	void Update(float dt);

	void UpdatePhysics(float dt);

	void Move(float dt);

	void Jump();
	void ShortJump();

	void Collision(Platform platform);

	void Draw(sf::RenderWindow& window);


private:
	bool is_grounded = true;
	bool is_jumping = false;
	bool is_walking = false;

	PLAYERSTATE pState;

	sf::Vector2f velocity;
	sf::Vector2f acceleration;

};