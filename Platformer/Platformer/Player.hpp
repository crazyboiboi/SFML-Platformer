#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "Definitions.hpp"
#include "Platform.hpp"
#include "Enemy.hpp"

class Player : public Entity {

public:
	Player(sf::Texture& spritesheet, float posX, float posY, sf::Vector2f size);
	~Player();

	void Reset();

	void LoadAnimSprites(sf::Texture& spritesheet);

	void Update(float dt, std::vector<Platform> platforms, std::vector<Enemy> enemies);

	void Move(float dt);
	void Animate(float dt);

	void Jump();
	void ShortJump();

	void Collision(std::vector<Platform> platforms, std::vector<Enemy> enemies);

	void Draw(sf::RenderWindow& window);

	bool playerIsDead();


private:
	bool is_grounded = false;
	bool is_jumping = true;
	bool is_walking = false;
	bool is_dead = false;

	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	
	int current_frame = 0;
	float duration = 0.0f;
	std::vector<sf::IntRect> idle_anim;
	std::vector<sf::IntRect> walk_anim;
	sf::IntRect jump_anim;
};