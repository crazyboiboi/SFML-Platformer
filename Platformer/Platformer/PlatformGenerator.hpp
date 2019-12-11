#pragma once

#include <SFML/Graphics.hpp>
#include "Platform.hpp"
#include "Camera.hpp"


class PlatformGenerator {

public:
	PlatformGenerator();
	~PlatformGenerator();

	void SpawnPlatform();
	void RemovePlatform(Camera& camera);

	void Draw(sf::RenderWindow& window);
	void Update(Camera& camera);

	std::vector<Platform> GetPlatforms();

private:
	std::vector<Platform> platforms;
	int _maxSize = 8;
};