
#include "HUD.hpp"
#include <iostream>

HUD::HUD() {
	LoadAsset();

	//Load font
	_scoreText.setFont(_font);
	_scoreText.setString("0");
	_scoreText.setCharacterSize(48);
	_scoreText.setFillColor(sf::Color::White);
	_scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);

	//Pause Button

}

HUD::~HUD() { }

void HUD::LoadAsset() {
	if (!_font.loadFromFile(GAME_FONT)) {
		std::cout << "ERROR" << std::endl;
	}
}


void HUD::Draw(sf::RenderWindow& window) {
	window.draw(_scoreText);
}

void HUD::UpdateScore(int score, Camera& camera) {
	_scoreText.setString(std::to_string(score));
	_scoreText.setPosition(camera.getPosition().x, camera.getPosition().y - SCREEN_HEIGHT/2.5);
}