#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#include "GameStateMenu.h"
#include "GameStatePlay.h"
#include "GameState.h"

void GameStateMenu::startGame() {
	game->pushState(new GameStatePlay(this->game));
	return;
}

void GameStateMenu::draw() {
	game->Gamewindow->clear(sf::Color::Black);
	game->Gamewindow->setView(this->view);

	game->Gamewindow->draw(GameStateMenu::startButton);
	game->Gamewindow->display();

	return;
}

void GameStateMenu::update() {

}

void GameStateMenu::highlightItems(sf::Vector2f mousePos) {
	// TODO: Extend for multiple menu items

	if (this->startButton.getGlobalBounds().contains(mousePos)) {
		this->startButton.setFillColor(sf::Color(100, 250, 250));
	} else {
		this->startButton.setFillColor(sf::Color(255, 255, 255));
	}

	return;
}

std::string GameStateMenu::getClickedItem(sf::Vector2f mousePos) {
	// TODO: Extend for multiple menu items
	
	if (this->startButton.getGlobalBounds().contains(mousePos)) {
		return "start_game";
	}
	return "";
}

void GameStateMenu::handleInput() {
	sf::Event event;
	sf::Vector2f mousePos = game->Gamewindow->mapPixelToCoords(sf::Mouse::getPosition(*game->Gamewindow), this->view);

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
			case sf::Event::MouseMoved: // Highlight menu items on hover
				highlightItems(mousePos);
				break;
			case sf::Event::MouseButtonPressed: // Click on menu items
				if (event.mouseButton.button == sf::Mouse::Left) {
					std::string item = getClickedItem(mousePos);
					if (item == "start_game") this->startGame();
				}
				break;
		}
	}
}

GameStateMenu::GameStateMenu(Gameengine* game) {
	this->game = game;
	float zoom = 1.0f; // No zoom

	sf::Vector2f pos = sf::Vector2f(game->Gamewindow->getSize());
	this->view.setSize(pos);
	this->view.zoom(zoom);

	// Get centre
	pos *= 0.5f;
	this->view.setCenter(pos * zoom);

	GameStateMenu::startButton = sf::RectangleShape(sf::Vector2f(200.0f, 32.0f));
	GameStateMenu::startButton.setFillColor(sf::Color::White);
	GameStateMenu::startButton.setOutlineColor(sf::Color(200, 200, 200));
	GameStateMenu::startButton.setOutlineThickness(2.0f);
	GameStateMenu::startButton.setPosition(sf::Vector2f(100.0f, 184.0f));
}