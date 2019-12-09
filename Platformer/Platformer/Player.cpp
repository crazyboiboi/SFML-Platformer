#include "Player.hpp"
#include <iostream>


Player::Player(std::string imgDirectory, float posX, float posY, sf::Vector2f size) {
	rect.setSize(size);
	rect.setOrigin(size / 2.0f);
	rect.setPosition(posX, posY);

	std::cout << "INITIALISED" << std::endl;

	rect.setFillColor(sf::Color::White);
	pState = PLAYERSTATE::STAND;
}

Player::~Player() { std::cout << "OBJECT REMOVED" << std::endl; }





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


void Player::Update(float dt) {
	Move(dt);
	rect.move(velocity + (acceleration));
	UpdatePhysics(dt);
}


void Player::ShortJump() {
	if (is_jumping) {
		if (velocity.y < -3) {
			velocity.y = -3;
		}
	}
}


void Player::Jump() {
	is_grounded = rect.getPosition().y == (SCREEN_HEIGHT-rect.getSize().y/2) ? true : false; 
	std::cout << is_grounded << std::endl;
	if (is_grounded && !is_jumping) {
		is_jumping = true;
		velocity.y = -PLAYER_JUMP;
	}

}


void Player::Collision(Platform platform) {
	float right = rect.getPosition().x + (rect.getSize().x/2);

	if (right >= platform.left) {
		rect.setPosition(platform.left-(rect.getSize().x/2), rect.getPosition().y);
	}

}


void Player::Draw(sf::RenderWindow& window) {
	window.draw(rect);
}