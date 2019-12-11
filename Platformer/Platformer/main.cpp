#include <SFML/Graphics.hpp>
#include <iostream>
#include "DEFINITIONS.hpp"
#include "Player.hpp"
#include "Platform.hpp"
#include "Camera.hpp"
#include "PlatformGenerator.hpp"


int main() {
	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(600, 800), "Platformer");
	window.setFramerateLimit(60);

	//Game Objects
	Player player("images", 100, 600, sf::Vector2f(50, 50));
	
	PlatformGenerator platform;

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


		//Draw
		window.clear();

		platform.Draw(window);

		player.Draw(window);


		window.display();

	}
	return 0;
}