#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace std;

#include "tile.h"
#include "Map.h"

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
	tile* testtile = new tile(2, 2, 1);
	float value = testtile->getwidth();
	std::cout << value;

	//Defines Window Size
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!", sf::Style::Close | sf::Style::Resize);

	//Player
	sf::RectangleShape player(sf::Vector2f(50.0f, 50.0f));
	player.setFillColor(sf::Color::White);

	//Map information, pls no fixed sizes BOOSTED CODE DELET THIS
	vector<sf::RectangleShape> tilelist(16);
	//useless rn
	Map* level1 = new Map();
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++){
			tilelist[(4*i)+j] = sf::RectangleShape(sf::Vector2f( 50.0f, 50.0f ) );
			tilelist[(4*i)+j].setPosition( (i)*50.0f, (j)*50.0f );
			//Stripe Pattern
			if (j % 2 == 0)
				tilelist[(4 * i) + j].setFillColor(sf::Color::Blue);
			else
				tilelist[(4 * i) + j].setFillColor(sf::Color::Green);
	}

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
		//reset screen
		window.clear();
		//color tiles
		for (int i = 0; i < 16; i++) {
			window.draw(tilelist[i]);
		}
		window.draw(player);
		window.display();

	}
	return 0;
}