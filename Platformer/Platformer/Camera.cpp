
#include "Camera.hpp"

Camera::Camera() {
	view.setSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	view.setCenter(0.0f, 0.0f);
}

Camera::~Camera() { }

void Camera::Update(float dt, Player player) {
	if (player.rect.getPosition().y < SCREEN_HEIGHT / 4) {
		sf::Vector2f movement = player.rect.getPosition() - GetPosition();
		view.move(movement * dt);
	}
}

sf::Vector2f Camera::GetPosition() {
	return view.getCenter();
}


void Camera::Render(sf::RenderWindow& window) {
	window.setView(view);
}