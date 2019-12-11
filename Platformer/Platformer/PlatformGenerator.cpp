
#include "PlatformGenerator.hpp"
#include <iostream>

PlatformGenerator::PlatformGenerator() {
	Platform platform1("hmm", 0, 720, sf::Vector2f(800, 100));
	//Platform platform2("hmm", 125, 575, sf::Vector2f(200, 30));
	//Platform platform3("hmm", 400, 380, sf::Vector2f(200, 30));
	//Platform platform4("hmm", 300, 240, sf::Vector2f(200, 30));
	//Platform platform5("hmm", 500, 0, sf::Vector2f(200, 30));


	platforms.push_back(platform1);
	//platforms.push_back(platform2);
	//platforms.push_back(platform3);
	//platforms.push_back(platform4);
	//platforms.push_back(platform5);
}


PlatformGenerator::~PlatformGenerator() { }


void PlatformGenerator::Update(Camera& camera) {
	RemovePlatform(camera);
	if (platforms.size() < _maxSize) {
		SpawnPlatform();
		std::cout << platforms.size() << std::endl;
	}
}


void PlatformGenerator::SpawnPlatform() {
	int width = rand() % (PLATFORM_MAX_LENGTH - PLATFORM_MIN_LENGTH + 1) + PLATFORM_MIN_LENGTH;
	float height = rand() % (PLATFORM_MAX_HEIGHT - PLATFORM_MIN_HEIGHT + 1) + PLATFORM_MIN_HEIGHT;

	float posX = rand() % (SCREEN_WIDTH - width + 1);
	float posY = rand() % (200 - 100 + 1) + 100;
	sf::Vector2f newPosition = sf::Vector2f(posX, platforms.back().rect.getPosition().y - posY);

	Platform newPlat("hmm", newPosition.x, newPosition.y, sf::Vector2f(width, height));
	platforms.push_back(newPlat);
}


void PlatformGenerator::RemovePlatform(Camera &camera) {
	for (int i = 0; i < platforms.size(); i++) {
		if (platforms[i].rect.getPosition().y - camera.getPosition().y > SCREEN_HEIGHT/2) {
			platforms.erase(platforms.begin()+i);
		}
	}
}


void PlatformGenerator::Draw(sf::RenderWindow& window) {
	for (Platform p : platforms) {
		p.Draw(window);
	}
}


std::vector<Platform> PlatformGenerator::GetPlatforms() { 
	return platforms;
}

