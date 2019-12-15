#pragma once

#include <SFML/Graphics.hpp>
#include "Enemy.hpp"

class EnemySpawner {

public:
	EnemySpawner(sf::Texture& spritesheet);
	~EnemySpawner();

	void SpawnEnemy();
	void RemoveEnemy();

	void Draw(sf::RenderWindow& window);
	
	void Update(float dt);

private:
	int _maxEnemies;

	sf::Texture _spritesheet;

	std::vector<Enemy> enemies;

	std::vector<sf::IntRect> anim;

};