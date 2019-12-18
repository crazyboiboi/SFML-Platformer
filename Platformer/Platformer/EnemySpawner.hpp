#pragma once

#include <SFML/Graphics.hpp>
#include "Enemy.hpp"
#include "Player.hpp"

class EnemySpawner {

public:
	EnemySpawner(sf::Texture& spritesheet);
	~EnemySpawner();

	void Reset();

	void SpawnEnemy(Player player);
	void RemoveEnemy();

	void Draw(sf::RenderWindow& window);
	
	void Update(float dt, Player player);

	std::vector<Enemy> GetEnemies();

private:
	int _maxEnemies;

	sf::Texture _spritesheet;

	std::vector<Enemy> enemies;

	std::vector<sf::IntRect> anim;

};