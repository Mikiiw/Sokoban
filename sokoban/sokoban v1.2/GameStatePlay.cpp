#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameStatePlay.h"
#include "GameState.h"

void GameStatePlay::createPlayer() {
	GameStatePlay::Player = sf::RectangleShape(sf::Vector2f(50.0f, 50.0f));
	GameStatePlay::Player.setFillColor(sf::Color::White);
}

void GameStatePlay::drawMap() {
	//useless rn
	tilelist = std::vector<sf::RectangleShape>(16);
	//Map* level1 = new Map();
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			tilelist[(4 * i) + j] = sf::RectangleShape(sf::Vector2f(50.0f, 50.0f));
			tilelist[(4 * i) + j].setPosition((i)*50.0f, (j)*50.0f);
			//Stripe Pattern
			if ((j + i) % 2 == 0)
				tilelist[(4 * i) + j].setFillColor(sf::Color::Blue);
			else
				tilelist[(4 * i) + j].setFillColor(sf::Color::Green);
		}
}

void GameStatePlay::draw() {
	/*reset screen*/
	game->Gamewindow->clear();

	// Set this as current view
	game->Gamewindow->setView(this->view);

	//color tiles
	for (int i = 0; i < 16; i++) {
		game->Gamewindow->draw(tilelist[i]);
	}
	game->Gamewindow->draw(GameStatePlay::Player);
	game->Gamewindow->display();
}

void GameStatePlay::update() {
	
}

void GameStatePlay::handleInput() {
	sf::Event event;

	while (game->Gamewindow->pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			game->Gamewindow->close();
			break;
		case sf::Event::Resized:
			std::cout << "New Width: " << event.size.width << " New Height: " << event.size.height << std::endl;
			break;
		case sf::Event::TextEntered:
			if (event.text.unicode < 128) {
				printf("%c", event.text.unicode);
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
}

GameStatePlay::GameStatePlay(Gameengine* game) {
	this->game = game;
	float zoom = 0.5f; // Zoom out to double size
	
	sf::Vector2f pos = sf::Vector2f(game->Gamewindow->getSize());
	this->view.setSize(pos);
	this->view.zoom(zoom);

	// Get centre
	pos *= 0.5f;
	this->view.setCenter(pos * zoom);

	createPlayer();
	drawMap();
}