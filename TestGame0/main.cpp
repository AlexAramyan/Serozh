#include <iostream>

#include <SFML/Graphics.hpp>

#include "Player.hpp"
#include "Enemy.hpp"

#define w_screen 720
#define h_screen 480

#define target_texture "img/target.png"

#define res_s_player "img/sprite.png"
#define res_s_world "img/worldsprites.png"
#define res_s_kim "img/kim.jpg"

#define world_sizes 145,0,154,56

int main() {
	sf::RenderWindow app(sf::VideoMode(w_screen, h_screen), "test0");
	app.setMouseCursorVisible(0);
	app.setFramerateLimit(60);

#pragma region setcursor
	sf::View fixed = app.getView();
	sf::Texture t_m_cur;
	t_m_cur.loadFromFile(target_texture);
	sf::Sprite m_cur(t_m_cur);
	m_cur.setScale(0.117647058823529f, 0.117647058823529f);
#pragma endregion
	
	Player pl(res_s_player);
	pl.makebigger(2);
	pl.setPosition(8, 192);

	sf::Texture t_world;
	t_world.loadFromFile(res_s_world);
	sf::Sprite s_world;
	s_world.setTexture(t_world);
	s_world.setTextureRect(sf::IntRect(world_sizes));
	s_world.setPosition(-10.0f, 256.0f);
	s_world.setScale(5.0f, 5.0f);

	Enemy kim(res_s_kim);
	kim.makeBigger(0.25f);
	kim.setPosition(600, -120);

	//sf::RectangleShape lzr;

	Bullet bul;

	sf::Clock clock;
	sf::Mouse mymouse;

	bool ready = false;

	while (app.isOpen())
	{
		sf::Event e;
		while (app.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
			{
				app.close();
			}
		}
//		lzr.setPosition(pl.sprite.getPosition().x, pl.sprite.getPosition().y);
		m_cur.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(app)));

		//moving
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			pl.animate('l', 8);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			pl.animate('r', 8);
		}

		//shooting
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			//bul.moveto()
			std::cout << "Piew-Piew\n";
		}

		//Kim's coming
		if (clock.getElapsedTime().asSeconds() > 3)
		{
			ready = 1;
		}
		if (ready)
		{
			if (kim.getPosition().y < 20)
			{
				kim.setPosition(kim.getPosition().x, kim.getPosition().y + 1);
			}
		}

		/*if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			lzr.setFillColor(sf::Color::Red);
			lzr.setPosition(pl.sprite.getPosition().x, pl.sprite.getPosition().y);

			double length = (std::sqrt(
				std::pow((pl.sprite.getPosition().y - sf::Mouse::getPosition().y), 2) +
				std::pow((pl.sprite.getPosition().x - sf::Mouse::getPosition().x), 2)
			));

			double sin = ((pl.sprite.getPosition().y - sf::Mouse::getPosition().y) / length);
			double angle = std::asin(sin);
			angle = (angle * 180 / PI);

			lzr.setRotation(-angle - 15);
			lzr.setSize(sf::Vector2f(length - 350, 3));
		}*/

		/*else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			pl.animate('d', 8);
		}*/
		/*else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			pl.animate('u', 8);
		}*/

		/*system("cls");
		std::cout << pl.sprite.getPosition().x << " " << pl.sprite.getPosition().y;*/

		//clear screen and display
		app.clear();
		app.setView(fixed);
		app.draw(m_cur);
		app.draw(kim.s_enemy);
		//app.draw(lzr);
		app.draw(pl.sprite);
		app.draw(s_world);
		app.display();
	}
}