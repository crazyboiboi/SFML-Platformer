
#include "Enemy.hpp"
#include <iostream>

//566, 510, 122, 139
//568, 1534, 122, 135

Enemy::Enemy(sf::Texture& spritesheet, float posX, float posY, bool going_left, sf::Vector2f size) {
	sprite.setTexture(spritesheet);
	sprite.setTextureRect(sf::IntRect(566, 510, 122, 139));
	sprite.setPosition(posX, posY);

	rect.setSize(size);
	rect.setPosition(posX, posY);
	rect.setFillColor(sf::Color::Green);

	left = rect.getPosition().x;
	right = rect.getPosition().x + rect.getSize().x;
	top = rect.getPosition().y;
	bottom = rect.getPosition().y + rect.getSize().y;

	if (going_left) {
		velocity = sf::Vector2f(-2.0f, 0.0f);
	}
	else {
		velocity = sf::Vector2f(2.0f, 0.0f);
	}
}

Enemy::~Enemy() { }

void Enemy::Update(float dt) {
	rect.move(velocity);

	if (rect.getPosition().x + rect.getSize().x < 0) {
		_outOfFrame = true;
	}
	if (rect.getPosition().x - rect.getSize().x > SCREEN_WIDTH) {
		_outOfFrame = true;
	}
	sprite.setPosition(rect.getPosition());
}


bool Enemy::outOfFrame() {
	return _outOfFrame;
}


void Enemy::Draw(sf::RenderWindow& window) {
	//window.draw(rect);
	window.draw(sprite);
}