#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Player.hpp"

class Camera {

public:
	Camera();
	~Camera();

	void Update(float dt, Player player);
	void Render(sf::RenderWindow& window);
	sf::Vector2f getPosition();

private:
	sf::View view;

};