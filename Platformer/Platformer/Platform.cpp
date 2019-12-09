
#include <iostream>
#include "Platform.hpp"

Platform::Platform(std::string imgDirectory, float posX, float posY, sf::Vector2f size) {
	std::cout << "INITIALISED" << std::endl;

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
	window.draw(rect);
}