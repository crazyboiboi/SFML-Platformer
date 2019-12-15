#pragma once

#include <SFML/Graphics.hpp>
#include "Platform.hpp"
#include "Camera.hpp"


class PlatformGenerator {

public:
	PlatformGenerator(sf::Texture& spritesheet);
	~PlatformGenerator();

	void Initialize();

	void SpawnPlatform();
	void RemovePlatform(Camera& camera);

	void Draw(sf::RenderWindow& window);
	void Update(Camera& camera);

	std::vector<Platform> GetPlatforms();
	int GetScore();

private:
	sf::Texture _spritesheet;
	sf::IntRect platform_image;

	std::vector<Platform> platforms;
	int _maxSize = 8;

	int _score;
};