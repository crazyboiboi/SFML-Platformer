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

private:
	sf::View view;
};