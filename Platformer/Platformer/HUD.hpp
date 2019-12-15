#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Camera.hpp"


class HUD {

public:
	HUD();
	~HUD();

	void LoadAsset();
	void Draw(sf::RenderWindow& window);
	void UpdateScore(int score, Camera& camera);

private:
	sf::Font _font;

	sf::Text _scoreText;


};