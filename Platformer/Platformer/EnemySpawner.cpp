
#include "EnemySpawner.hpp"
#include <iostream>

EnemySpawner::EnemySpawner(sf::Texture& spritesheet) {
	_spritesheet = spritesheet;

	anim.push_back(sf::IntRect(566, 510, 122, 139));
	anim.push_back(sf::IntRect(568, 1534, 122, 135));

	Enemy enemy1(_spritesheet, 0, 100, false, sf::Vector2f(90, 100));
	Enemy enemy2(_spritesheet, SCREEN_WIDTH, 400, true, sf::Vector2f(90, 100));
	enemies.push_back(enemy1);
	enemies.push_back(enemy2);

	_maxEnemies = 2;
}

EnemySpawner::~EnemySpawner() { }

void EnemySpawner::Reset() {
	enemies.clear();
	Enemy enemy1(_spritesheet, 0, 100, false, sf::Vector2f(90, 100));
	Enemy enemy2(_spritesheet, SCREEN_WIDTH, 400, true, sf::Vector2f(90, 100));
	enemies.push_back(enemy1);
	enemies.push_back(enemy2);
}

void EnemySpawner::SpawnEnemy(Player player) {
	float posX = rand()%(2) == 1 ? -40.0f : SCREEN_WIDTH;
	float posY = rand() % (800);
	bool going_left = posX == -40.0f ? false : true;

	posY += rand()%(400);

	Enemy enemy(_spritesheet, posX, player.rect.getPosition().y - posY, going_left, sf::Vector2f(90, 100));
	enemies.push_back(enemy);
}

void EnemySpawner::Update(float dt, Player player) {
	RemoveEnemy();
	if (enemies.size() < _maxEnemies) {
		SpawnEnemy(player);
	}
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i].Update(dt);
	}
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


std::vector<Enemy> EnemySpawner::GetEnemies() {
	return enemies;
}