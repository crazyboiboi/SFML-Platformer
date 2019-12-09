#include <SFML/Graphics.hpp>
#include <iostream>
#include "DEFINITIONS.hpp"
#include "Player.hpp"
#include "Platform.hpp"


int main() {
	sf::RenderWindow window(sf::VideoMode(600, 800), "Platformer");
	window.setFramerateLimit(60);

	//Game Objects
	Player player("images", 375, 775, sf::Vector2f(50, 50));
	
	Platform platform1("hmm", 500, 720, sf::Vector2f(200, 80));
	Platform platform2("hmm", 125, 625, sf::Vector2f(200, 30));

	sf::Event event;
	sf::Clock clock;
	sf::Time time;

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
		float dt = clock.restart().asSeconds();


		//Process Input


		//Update
		player.Update(dt);

		player.Collision(platform1);

		//Draw
		window.clear();

		player.Draw(window);

		platform1.Draw(window);
		platform2.Draw(window);

		window.display();

	}
	return 0;
}