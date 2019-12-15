#include "Player.hpp"
#include <iostream>


Player::Player(sf::Texture& spritesheet, float posX, float posY, sf::Vector2f size) {
	rect.setOrigin(size / 2.0f);
	rect.setSize(size);
	rect.setPosition(posX, posY);
	rect.setFillColor(sf::Color::White);

	sprite.setOrigin(rect.getOrigin().x+10, rect.getOrigin().y);
	LoadAnimSprites(spritesheet);
}

Player::~Player() { }


void Player::LoadAnimSprites(sf::Texture& spritesheet) {
	sprite.setTexture(spritesheet);

	idle_anim.push_back(sf::IntRect(614, 1063, 120, 191));
	idle_anim.push_back(sf::IntRect(690, 406, 120, 201));

	walk_anim.push_back(sf::IntRect(678, 860, 120, 201));
	walk_anim.push_back(sf::IntRect(692, 1458, 120, 207));

	jump_anim = sf::IntRect(382, 763, 150, 181);

	sprite.setTextureRect(idle_anim[0]);
}




void Player::Move(float dt) {
	acceleration = sf::Vector2f(0, PLAYER_GRAV);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		acceleration.x = -PLAYER_ACC;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		acceleration.x = PLAYER_ACC;
	}

	acceleration.x += velocity.x * PLAYER_FRIC;
	velocity += acceleration;
	if (abs(velocity.x) < 0.5) {
		velocity.x = 0;
	}
	acceleration.x = acceleration.x * 0.5;
}



void Player::Update(float dt, std::vector<Platform> platforms, std::vector<Enemy> enemies) {
	Animate(dt);
	Move(dt);
	rect.move(velocity + acceleration);
	Collision(platforms, enemies);

	if (rect.getPosition().x + (rect.getSize().x / 2) < 0) {
		rect.setPosition(SCREEN_WIDTH+ (rect.getSize().x / 2), rect.getPosition().y);
	}
	if (rect.getPosition().x - (rect.getSize().x / 2) > SCREEN_WIDTH) {
		rect.setPosition(0 - (rect.getSize().x / 2), rect.getPosition().y);
	}
	if (platforms[0].rect.getPosition().y - rect.getPosition().y < -300) {
		is_dead = true;
	}
	sprite.setPosition(rect.getPosition());

}


void Player::ShortJump() {
	if (is_jumping) {
		if (velocity.y < -3) {
			velocity.y = -3;
		}
	}
}


void Player::Jump() {
	//is_grounded = rect.getPosition().y == (SCREEN_HEIGHT-rect.getSize().y/2) ? true : false; 
	if (is_grounded && !is_jumping) {
		is_jumping = true;
		velocity.y = -PLAYER_JUMP;
	}

}


void Player::Animate(float dt) {
	if (velocity.x != 0) {
		is_walking = true;
	}
	else {
		is_walking = false;
	}
	
	if (is_walking) {
		sprite.setTextureRect(walk_anim[current_frame]);
		duration += dt;
		if (duration > 0.25f) {
			duration -= 0.25f;
			current_frame = (current_frame + 1) % (idle_anim.size());
		}
		if (acceleration.x < 0.0f) {
			sprite.setScale(-1.0f, 1.0f);
		}
		else {
			sprite.setScale(1.0f, 1.0f);
		}
	}

	if (is_jumping) {
		sprite.setTextureRect(jump_anim);
	}


	if (!is_walking && !is_jumping) {
		sprite.setTextureRect(idle_anim[current_frame]);
		duration += dt;
		if (duration > 0.75f) {
			duration -= 0.75f;
			current_frame = (current_frame + 1) % (idle_anim.size());
			if (current_frame == 1) {
				sprite.setOrigin(rect.getOrigin().x + 10, rect.getOrigin().y+10);

			}
			else {
				sprite.setOrigin(rect.getOrigin().x + 10, rect.getOrigin().y);
			}
		}
	}
}


void Player::Collision(std::vector<Platform> platforms, std::vector<Enemy> enemies) {
	bottom = rect.getPosition().y + (rect.getSize().y / 2);
	top = bottom - 20;	//3rd quarter

	for (size_t i = 0; i < platforms.size(); i++)
	{
		if (velocity.y > 0) {
			if (rect.getGlobalBounds().intersects(platforms[i].rect.getGlobalBounds())) {
				if (top < platforms[i].bottom && bottom >= platforms[i].top && top) {
					rect.setPosition(rect.getPosition().x, platforms[i].top - (rect.getSize().y / 2));
					velocity.y = 0;
					is_grounded = true;
					is_jumping = false;
				}
			}
		}
	}	

	for (size_t i = 0; i < enemies.size(); i++)
	{
		if (rect.getGlobalBounds().intersects(enemies[i].rect.getGlobalBounds())) {
			is_dead = true;
		}
	}
}


void Player::Draw(sf::RenderWindow& window) {
	//window.draw(rect);
	window.draw(sprite);
}