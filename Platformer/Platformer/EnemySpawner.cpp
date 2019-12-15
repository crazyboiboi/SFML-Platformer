
#include "EnemySpawner.hpp"
#include <iostream>

EnemySpawner::EnemySpawner(sf::Texture& spritesheet) {
	_spritesheet = spritesheet;

	anim.push_back(sf::IntRect(566, 510, 122, 139));
	anim.push_back(sf::IntRect(568, 1534, 122, 135));

	_maxEnemies = 1;
}

EnemySpawner::~EnemySpawner() { }

void EnemySpawner::SpawnEnemy() {
	Enemy enemy(_spritesheet, SCREEN_WIDTH, 500, true, sf::Vector2f(122, 139));
	enemies.push_back(enemy);
}

void EnemySpawner::Update(float dt) {
	RemoveEnemy();
	if (enemies.size() < _maxEnemies) {
		SpawnEnemy();
	}
	enemies[0].Update(dt);
}

void EnemySpawner::RemoveEnemy() {
	for (Enemy e : enemies) {
		if (e.outOfFrame()) {
			enemies.erase(enemies.begin());
		}
	}
}

void EnemySpawner::Draw(sf::RenderWindow& window) {
	for (Enemy e : enemies) {
		e.Draw(window);
	}
}
