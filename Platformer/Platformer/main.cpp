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


		//Process Input


		//Update
		player.Update(dt, platform.GetPlatforms());
		camera.Update(dt, player);
		platform.Update(camera);
		enemySpawner.Update(dt);

		hud.UpdateScore(platform.GetScore(), camera);

		//Draw
		window.clear(sf::Color(94, 244, 255));

		platform.Draw(window);
		player.Draw(window);
		enemySpawner.Draw(window);
		hud.Draw(window);

		window.display();

	}
	return 0;
}