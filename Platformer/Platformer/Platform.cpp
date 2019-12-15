#include <iostream>
#include "Platform.hpp"



Platform::Platform(sf::Texture& spritesheet, sf::IntRect intrect, float posX, float posY, sf::Vector2f size) {
	sprite.setTexture(spritesheet);
	sprite.setTextureRect(intrect);
	sprite.setPosition(posX, posY);
	sprite.setScale(size.x / 370, size.y / 85);

	rect.setSize(size);
	rect.setPosition(posX, posY);
	rect.setFillColor(sf::Color::Green);

	left = rect.getPosition().x;
	right = rect.getPosition().x + rect.getSize().x;
	top = rect.getPosition().y;
	bottom = rect.getPosition().y + rect.getSize().y;
}

Platform::~Platform() { }


void Platform::Draw(sf::RenderWindow& window) {
	//window.draw(rect);
	window.draw(sprite);
}