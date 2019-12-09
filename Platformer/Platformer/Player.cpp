#include "Player.hpp"
#include <iostream>


Player::Player(std::string imgDirectory, float posX, float posY, sf::Vector2f size) {
	rect.setSize(size);
	rect.setOrigin(size / 2.0f);
	rect.setPosition(posX, posY);

	std::cout << "INITIALISED" << std::endl;

	rect.setFillColor(sf::Color::White);
}

Player::~Player() { }





void Player::Move(float dt) {
	acceleration = sf::Vector2f(0, PLAYER_GRAV);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		acceleration.x = -PLAYER_ACC;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		acceleration.x = PLAYER_ACC;
	}

	acceleration.x += velocity.x * PLAYER_FRIC;
	velocity += acceleration;
	if (abs(velocity.x) < 0.5) {
		velocity.x = 0;
	}
	acceleration.x = acceleration.x * 0.5;
}


void Player::UpdatePhysics(float dt) {
	//Check if player position and determine if it is grounded
	if (rect.getPosition().y >= SCREEN_HEIGHT - (rect.getSize().y / 2)) {
		rect.setPosition(rect.getPosition().x, SCREEN_HEIGHT - (rect.getSize().y / 2));
		is_grounded = true;
		is_jumping = false;
	}
	else {
		is_grounded = false;
	}
}


void Player::Update(float dt, std::vector<Platform> platforms) {
	Move(dt);
	rect.move(velocity + (acceleration));
	//UpdatePhysics(dt);
	Collision(platforms);
}


void Player::ShortJump() {
	if (is_jumping) {
		if (velocity.y < -3) {
			velocity.y = -3;
		}
	}
}


void Player::Jump() {
	//is_grounded = rect.getPosition().y == (SCREEN_HEIGHT-rect.getSize().y/2) ? true : false; 
	if (is_grounded && !is_jumping) {
		is_jumping = true;
		velocity.y = -PLAYER_JUMP;
	}

}


void Player::Collision(std::vector<Platform> platforms) {
	bottom = rect.getPosition().y + (rect.getSize().y / 2);
	for (size_t i = 0; i < platforms.size(); i++)
	{
		if (velocity.y > 0) {
			if (rect.getGlobalBounds().intersects(platforms[i].rect.getGlobalBounds())) {
				if (bottom >= platforms[i].top) {
					rect.setPosition(rect.getPosition().x, platforms[i].top - (rect.getSize().y / 2));
					velocity.y = 0;
					is_grounded = true;
					is_jumping = false;
				}
			}
		}
	}	
}


void Player::Draw(sf::RenderWindow& window) {
	window.draw(rect);
}