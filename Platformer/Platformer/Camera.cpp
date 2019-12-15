
#include "Camera.hpp"
#include <iostream>

Camera::Camera() {
	view.reset(sf::FloatRect(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT));
}

Camera::~Camera() { }

void Camera::Update(float dt, Player player) {
	if (player.rect.getPosition().y < SCREEN_HEIGHT / 4) {
		//sf::Vector2f movement(0.0f, player.rect.getPosition().y+20);
		sf::Vector2f movement(0.0f, player.rect.getPosition().y - view.getCenter().y);
		view.move(movement * CAMERA_SPEED *dt);
		view.setCenter(view.getCenter());
	}
}


void Camera::Render(sf::RenderWindow& window) {
	window.setView(view);
}

sf::Vector2f Camera::getPosition() {
	return view.getCenter();
}