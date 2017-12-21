#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

#include "tile.h"

int main() {
	//sf::RenderWindow window(sf::VideoMode(1280, 720), "Title");

	//sf::CircleShape shape(200.0f);
	//shape.setFillColor(sf::Color::Blue);
	//while (window.isOpen()) {
	//	window.draw(shape);
	//	window.display();
	//}
	//return 0;

	//test region
	tile* testtile = new tile();

	testtile->setwidth(2);


	//Defines Window Size
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!", sf::Style::Close | sf::Style::Resize);
	//Player
	sf::RectangleShape player(sf::Vector2f(50.0f, 50.0f));
	player.setFillColor(sf::Color::White);

	//Creates a frame of our window
	while (window.isOpen())
	{
		sf::Event evnt;
		//Allows our frames to use events
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				std::cout << "New Width: " << evnt.size.width << " New Height: " << evnt.size.height << std::endl;
				break;
			case sf::Event::TextEntered:
				if (evnt.text.unicode < 128)
				{
					printf("%c", evnt.text.unicode);
				}
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			player.move(-0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			player.move(0.0f, -0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			player.move(0.1f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			player.move(0.0f, 0.1f);
		}

		window.clear();
		window.draw(player);
		window.display();

	}
	return 0;
}