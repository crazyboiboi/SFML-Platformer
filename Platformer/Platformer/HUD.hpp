#pragma once

#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "Camera.hpp"


class HUD {

public:
	HUD();
	~HUD();

	bool IsButtonClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window);

	void LoadAsset();
	void DrawGameOverScreen(sf::RenderWindow& window, Camera& camera);
	void DrawPauseScreen(sf::RenderWindow& window, Camera& camera);
	void Draw(sf::RenderWindow& window, Camera& camera);
	void UpdateScore(int score);
	BUTTON ButtonClicked( sf::RenderWindow& window);

private:
	int _score = 0;
	sf::Font _font;

	sf::RectangleShape background;
	sf::Sprite pauseButton;
	sf::Sprite resumeButton;
	sf::Sprite retryButton;
	sf::Sprite exitButton;

	sf::Text _scoreText;
	sf::Text _gameOverText;
	sf::Texture _pauseTex;
	sf::Texture _resumeTex;
	sf::Texture _retryTex;
	sf::Texture _exitTex;

};