#include <SFML/Graphics.hpp>
#include <iostream>
#include "DEFINITIONS.hpp"
#include "Player.hpp"
#include "Platform.hpp"


int main() {
	sf::RenderWindow window(sf::VideoMode(600, 800), "Platformer");
	window.setFramerateLimit(60);

	//Game Objects
	Player player("images", 100, 600, sf::Vector2f(50, 50));
	
	Platform platform1("hmm", 0, 720, sf::Vector2f(800, 100));
	Platform platform2("hmm", 125, 575, sf::Vector2f(200, 30));
	Platform platform3("hmm", 400, 380, sf::Vector2f(200, 30));
	Platform platform4("hmm", 300, 240, sf::Vector2f(200, 30));

	std::vector<Platform> platforms;
	platforms.push_back(platform1);
	platforms.push_back(platform2);
	platforms.push_back(platform3);
	platforms.push_back(platform4);

	sf::Event event;
	sf::Clock clock;
	sf::Time time;

	//Camera
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT));

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
		player.Update(dt, platforms);


		//Draw
		window.clear();

		for (Platform p : platforms) {
			p.Draw(window);
		}

		player.Draw(window);


		window.display();

	}
	return 0;
}