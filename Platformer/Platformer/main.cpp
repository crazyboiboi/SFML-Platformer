#include <SFML/Graphics.hpp>
#include <iostream>
#include "DEFINITIONS.hpp"
#include "Player.hpp"
#include "Platform.hpp"
#include "Camera.hpp"
#include "PlatformGenerator.hpp"
#include "HUD.hpp"
#include "Enemy.hpp"
#include "EnemySpawner.hpp"


int main() {
	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(600, 800), "Platformer");
	window.setFramerateLimit(60);

	sf::Texture spritesheet;
	if (!spritesheet.loadFromFile(SPRITESHEET)) {
		std::cout << "ERROR LOADING FILE" << std::endl;
	}

	//Game Objects
	Player player(spritesheet, 100, 600, sf::Vector2f(100, 190));

	PlatformGenerator platform(spritesheet);
	EnemySpawner enemySpawner(spritesheet);

	HUD hud;

	sf::Event event;
	sf::Clock clock;
	sf::Time time;

	//Camera
	Camera camera;

	int gamestate = GAMESTATE::START;
	bool gameOver = false;

	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Space) {
					player.Jump();
				}
			} if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::Space) {
					player.ShortJump();
				}
			}
		}

		camera.Render(window);

		float dt = clock.restart().asSeconds();		

		gameOver = player.playerIsDead();

		//Draw
		window.clear(sf::Color(94, 244, 255));

		//Input should be handled above, then set appropriate state
		//HUD should have different draws?
		switch (gamestate) {
		case GAMESTATE::START:
			//All update blocks should be in here
			//Check if pause button is clicked, set game to pause
			if (event.type == sf::Event::MouseButtonPressed) {
				BUTTON button = hud.ButtonClicked(window);
				if (button == BUTTON::PAUSEBTN) {
				gamestate = GAMESTATE::PAUSE;
				}
			}

			player.Update(dt, platform.GetPlatforms(), enemySpawner.GetEnemies());
			camera.Update(dt, player);
			platform.Update(camera);
			hud.UpdateScore(platform.GetScore());
			enemySpawner.Update(dt, player);

			if (gameOver) {
				gamestate = GAMESTATE::GAMEOVER;
			}

			platform.Draw(window);
			player.Draw(window);
			enemySpawner.Draw(window);
			hud.Draw(window, camera);
			break;
		case GAMESTATE::PAUSE:
			//Wait for key
			//Check if resume is pressed, set back to game start and resume
			//Check if quit
			if (event.type == sf::Event::MouseButtonPressed) {
				BUTTON button = hud.ButtonClicked(window);
				if (button == BUTTON::RESUMEBTN) {
					gamestate = GAMESTATE::START;
				}
				else if (button == BUTTON::QUITBTN) {
					gamestate = GAMESTATE::QUIT;
				}
			}

			platform.Draw(window);
			player.Draw(window);
			enemySpawner.Draw(window);
			hud.DrawPauseScreen(window, camera);
			break;
		case GAMESTATE::GAMEOVER:
			//Wait for key
			//If play again is pressed, set back to game start and reset the game
			//Else if exit button is pressed, exit the game using window.close()
			camera.Reset();

			if (event.type == sf::Event::MouseButtonPressed) {
				BUTTON button = hud.ButtonClicked(window);
				if (button == BUTTON::RETRYBTN) {
					clock.restart();
					player.Reset();
					platform.Reset();
					enemySpawner.Reset();
					gamestate = GAMESTATE::START;
				}
				else if (button == BUTTON::QUITBTN) {
					gamestate = GAMESTATE::QUIT;
				}
			}
			hud.DrawGameOverScreen(window, camera);
			break;
		case GAMESTATE::QUIT:
			window.close();
			break;
		}
		

		window.display();

	}
	return 0;
}
