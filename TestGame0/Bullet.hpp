#include "Player.hpp"

#pragma once
#include "utils.h"

struct Bullet
{
	Bullet(sf::Mouse m, Player p)
	{
		this->bullet.setFillColor(sf::Color::White);
		this->bullet.setSize(sf::Vector2f(5.0f, 3.0f));

		float triangle_a = p.sprite.getPosition().x - m.getPosition().x;
		float triangle_b = p.sprite.getPosition().y - m.getPosition().y;
		float tan = triangle_b / triangle_a;
		float angle = (float)(arctan(tan));

		this->bullet.setRotation(angle);
	};

	void moveto(sf::Mouse m, Player p) {
		float triangle_a = p.sprite.getPosition().x - m.getPosition().x;
		float triangle_b = p.sprite.getPosition().y - m.getPosition().y;
		float triangle_c = static_cast<float>(std::sqrt(std::pow(triangle_a, 2) + std::pow(triangle_b, 2)));

		float sin = triangle_a / triangle_c;
		float cos = triangle_b / triangle_c;
		
		float small_triangle_a = triangle_c * cos;
		float small_triangle_b = triangle_c * sin;

		this->bullet.setPosition((float)(this->bullet.getPosition().x - static_cast<int>(small_triangle_a / 2)), (float)(this->bullet.getPosition().y - static_cast<int>(small_triangle_b / 2)));
	};

	Player p;
	sf::RectangleShape bullet;
};
