
#include "PlatformGenerator.hpp"
#include <iostream>


PlatformGenerator::PlatformGenerator(sf::Texture& spritesheet) {
	_spritesheet = spritesheet;
	platform_image = sf::IntRect(0, 288, 380, 94);
	Initialize();
}


void PlatformGenerator::Initialize() {
	Platform platform1(_spritesheet, platform_image, 0, 720, sf::Vector2f(380, 80));
	Platform platform2(_spritesheet, platform_image, 375, 575, sf::Vector2f(200, 70));

	platforms.push_back(platform1);
	platforms.push_back(platform2);
}


PlatformGenerator::~PlatformGenerator() { }


void PlatformGenerator::Reset() {
	platforms.clear();
	Initialize();
	_score = 0;
}


void PlatformGenerator::Update(Camera& camera) {
	RemovePlatform(camera);
	if (platforms.size() < _maxSize) {
		SpawnPlatform();
	}
}


void PlatformGenerator::SpawnPlatform() {
	int width = rand() % (PLATFORM_MAX_LENGTH - PLATFORM_MIN_LENGTH + 1) + PLATFORM_MIN_LENGTH;
	float height = rand() % (PLATFORM_MAX_HEIGHT - PLATFORM_MIN_HEIGHT + 1) + PLATFORM_MIN_HEIGHT;

	float posX = rand() % (SCREEN_WIDTH - width + 1);
	float posY = rand() % (250 - 150 + 1) + 150;
	sf::Vector2f newPosition = sf::Vector2f(posX, platforms.back().rect.getPosition().y - posY);

	Platform newPlat(_spritesheet, platform_image, newPosition.x, newPosition.y, sf::Vector2f(width, height));
	platforms.push_back(newPlat);
}


void PlatformGenerator::RemovePlatform(Camera &camera) {
	for (int i = 0; i < platforms.size(); i++) {
		if (platforms[i].rect.getPosition().y - camera.getPosition().y > SCREEN_HEIGHT/2) {
			platforms.erase(platforms.begin()+i);
			_score += 10;
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


int PlatformGenerator::GetScore() {
	return _score;
}