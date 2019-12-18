
#include "HUD.hpp"
#include <iostream>

HUD::HUD() {
	LoadAsset();

	//Score Text
	_scoreText.setFont(_font);
	_scoreText.setString("0");
	_scoreText.setCharacterSize(48);
	_scoreText.setFillColor(sf::Color::White);
	_scoreText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);

	
	//Game over text
	_gameOverText.setFont(_font);
	_gameOverText.setString("Game Over!!");
	_gameOverText.setCharacterSize(48);
	_gameOverText.setFillColor(sf::Color::White);
	_gameOverText.setOrigin(_scoreText.getGlobalBounds().width / 2, _scoreText.getGlobalBounds().height / 2);

	//Pause Button
	pauseButton.setTexture(_pauseTex);
	pauseButton.setScale(sf::Vector2f(0.4f, 0.4f));
	pauseButton.setOrigin(pauseButton.getGlobalBounds().width / 2, pauseButton.getGlobalBounds().height / 2);


	//Background
	background.setSize(sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));
	background.setFillColor(sf::Color(255, 255, 255, 100));
	background.setOrigin(background.getGlobalBounds().width / 2, background.getGlobalBounds().height / 2);	


	//Resume Button
	resumeButton.setTexture(_resumeTex);
	resumeButton.setScale(sf::Vector2f(0.4f, 0.4f));
	resumeButton.setOrigin(resumeButton.getGlobalBounds().width / 2, resumeButton.getGlobalBounds().height / 2);


	//Retry Button
	retryButton.setTexture(_retryTex);
	retryButton.setScale(sf::Vector2f(0.5f, 0.5f));
	retryButton.setOrigin(retryButton.getGlobalBounds().width / 2, retryButton.getGlobalBounds().height / 2);


	//Quit Button
	exitButton.setTexture(_exitTex);
	exitButton.setScale(sf::Vector2f(0.5f, 0.5f));
	exitButton.setOrigin(exitButton.getGlobalBounds().width / 2, exitButton.getGlobalBounds().height / 2);
}

HUD::~HUD() { }

void HUD::LoadAsset() {
	if (!_font.loadFromFile(GAME_FONT)) {
		std::cout << "ERROR" << std::endl;
	}
	if (!_pauseTex.loadFromFile(PAUSE_ICON)) {
		std::cout << "ERROR" << std::endl;
	}
	if (!_resumeTex.loadFromFile(RESUME_ICON)) {
		std::cout << "ERROR" << std::endl;
	}
	if (!_retryTex.loadFromFile(RETRY_ICON)) {
		std::cout << "ERROR" << std::endl;
	}
	if (!_exitTex.loadFromFile(EXIT_ICON)) {
		std::cout << "ERROR" << std::endl;
	}

}


void HUD::DrawGameOverScreen(sf::RenderWindow& window, Camera& camera) {
	_scoreText.setString("Score: " + std::to_string(_score));
	_scoreText.setPosition(camera.getPosition().x - SCREEN_WIDTH / 5, camera.getPosition().y - 25);

	_gameOverText.setPosition(camera.getPosition().x - SCREEN_WIDTH/5, camera.getPosition().y - 100);
	background.setPosition(camera.getPosition().x, camera.getPosition().y);
	retryButton.setPosition(camera.getPosition().x - 50, camera.getPosition().y + 50);
	exitButton.setPosition(camera.getPosition().x + 50, camera.getPosition().y + 50);

	window.draw(_scoreText);
	window.draw(_gameOverText);
	window.draw(background);
	window.draw(retryButton);
	window.draw(exitButton);

}


void HUD::DrawPauseScreen(sf::RenderWindow& window, Camera& camera) {
	background.setPosition(camera.getPosition().x, camera.getPosition().y);
	resumeButton.setPosition(camera.getPosition().x - 50, camera.getPosition().y);
	exitButton.setPosition(camera.getPosition().x + 50, camera.getPosition().y);

	window.draw(background);
	window.draw(resumeButton);
	window.draw(exitButton);
}


void HUD::Draw(sf::RenderWindow& window, Camera& camera) {
	_scoreText.setPosition(camera.getPosition().x, camera.getPosition().y - SCREEN_HEIGHT / 2.3);
	pauseButton.setPosition(camera.getPosition().x, camera.getPosition().y);

	window.draw(_scoreText);
	window.draw(pauseButton);
}

void HUD::UpdateScore(int score) {
	_score = score;
	_scoreText.setString(std::to_string(score));	
}


BUTTON HUD::ButtonClicked(sf::RenderWindow& window) {
	if (IsButtonClicked(pauseButton, sf::Mouse::Left, window)) {
		std::cout << "Pause!" << std::endl;
		return BUTTON::PAUSEBTN;
	}
	if (IsButtonClicked(resumeButton, sf::Mouse::Left, window)) {
		//std::cout << "Resume!" << std::endl;
		return BUTTON::RESUMEBTN;
	}
	if (IsButtonClicked(retryButton, sf::Mouse::Left, window)) {
		//std::cout << "Retry!" << std::endl;
		return BUTTON::RETRYBTN;
	}
	if (IsButtonClicked(exitButton, sf::Mouse::Left, window)) {
		//std::cout << "Quit!" << std::endl;
		return BUTTON::QUITBTN;
	}
	else {
		return BUTTON::DEFAULT;
	}
}


bool HUD::IsButtonClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window) {
	//Detect if mouse button is clicked
	if (sf::Mouse::isButtonPressed(button)) {
		sf::IntRect tempRect(object.getPosition().x-25, object.getPosition().y-25,
			object.getGlobalBounds().width, object.getGlobalBounds().height);

		if (tempRect.contains(sf::Mouse::getPosition(window))) {
			return true;
		}
	}
	return false;
}