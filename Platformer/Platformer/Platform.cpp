
#include <iostream>
#include "Platform.hpp"

Platform::Platform(std::string imgDirectory, float posX, float posY, sf::Vector2f size) {
	std::cout << "INITIALISED" << std::endl;

	rect.setSize(size);
	rect.setPosition(posX, posY);

	rect.setFillColor(sf::Color::Green);

	left = rect.getPosition().x;
}

Platform::~Platform() { std::cout << "PLATFORM DESTROYED" << std::endl; }


void Platform::Draw(sf::RenderWindow& window) {
	window.draw(rect);
}