#include <iostream>
#include <vector>

#include "Gameengine.h"
#include "Map.h"
#include <SFML/Graphics.hpp>

Gameengine::Gameengine() {

}

Gameengine::~Gameengine()
{
}


void Gameengine::initialise() {
	
	Gameengine::Gamewindow = new sf::RenderWindow(sf::VideoMode(200, 200), "Sokoban", sf::Style::Close | sf::Style::Resize);
}

void Gameengine::createPlayer() {
	Gameengine::Player = sf::RectangleShape(sf::Vector2f(50.0f, 50.0f));
	Gameengine::Player.setFillColor(sf::Color::White);
}

void Gameengine::loop() {
	createPlayer();
	drawMap();

	while (Gamewindow->isOpen())
	{
		sf::Event evnt;
		//Allows our frames to use events
		while (Gamewindow->pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				Gameengine::Gamewindow->close();
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

		//Player movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			Player.move(-0.1f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			Player.move(0.0f, -0.1f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			Player.move(0.1f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			Player.move(0.0f, 0.1f);
		}
		/*reset screen*/
			Gamewindow->clear();
			//color tiles
			for (int i = 0; i < 16; i++) {
				Gamewindow->draw(tilelist[i]);
			}
			Gameengine::Gamewindow->draw(Gameengine::Player);
			Gameengine::Gamewindow->display();
	}
}


void Gameengine::drawMap() {
	//useless rn
	tilelist = std::vector<sf::RectangleShape>(16);
	//Map* level1 = new Map();
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			tilelist[(4 * i) + j] = sf::RectangleShape(sf::Vector2f(50.0f, 50.0f));
			tilelist[(4 * i) + j].setPosition((i)*50.0f, (j)*50.0f);
			//Stripe Pattern
			if (j % 2 == 0)
				tilelist[(4 * i) + j].setFillColor(sf::Color::Blue);
			else
				tilelist[(4 * i) + j].setFillColor(sf::Color::Green);
		}
}
