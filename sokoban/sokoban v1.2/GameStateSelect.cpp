#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#include "GameStatePlay.h"
#include "GameStateOption.h"
#include "GameState.h"
#include "GameStateSelect.h"

void GameStateSelect::startGame() {
	gameengine->pushState(new GameStatePlay(this->gameengine));
	return;
}

void GameStateSelect::draw() {
	gameengine->Gamewindow->clear(sf::Color::Black);
	gameengine->Gamewindow->setView(this->view);

	gameengine->Gamewindow->draw(GameStateSelect::startButton);
	gameengine->Gamewindow->draw(GameStateSelect::startbuttontext);
	gameengine->Gamewindow->draw(GameStateSelect::optionButton);
	gameengine->Gamewindow->draw(GameStateSelect::optionbuttontext);
	gameengine->Gamewindow->draw(GameStateSelect::exitButton);
	gameengine->Gamewindow->draw(GameStateSelect::exitbuttontext);

	gameengine->Gamewindow->display();

	return;
}

void GameStateSelect::update() {

}

void GameStateSelect::highlightItems(sf::Vector2f mousePos) {
	// TODO: Extend for multiple menu items
	if (this->startButton.getGlobalBounds().contains(mousePos)) {
		this->startButton.setFillColor(sf::Color(100, 250, 250));
	}
	else {
		this->startButton.setFillColor(sf::Color(255, 255, 255));
	}

	if (this->optionButton.getGlobalBounds().contains(mousePos)) {
		this->optionButton.setFillColor(sf::Color(100, 250, 250));
	}
	else {
		this->optionButton.setFillColor(sf::Color(255, 255, 255));
	}

	if (this->exitButton.getGlobalBounds().contains(mousePos)) {
		this->exitButton.setFillColor(sf::Color(100, 250, 250));
	}
	else {
		this->exitButton.setFillColor(sf::Color(255, 255, 255));
	}
	return;
}

std::string GameStateSelect::getClickedItem(sf::Vector2f mousePos) {
	// TODO: Extend for multiple menu items
	if (this->startButton.getGlobalBounds().contains(mousePos))
		return "start_game";

	if (this->optionButton.getGlobalBounds().contains(mousePos))
		return "start_game";

	if (this->exitButton.getGlobalBounds().contains(mousePos))
		return "start_game";

	return "";
}

void GameStateSelect::handleInput() {
	sf::Event event;
	sf::Vector2f mousePos = gameengine->Gamewindow->mapPixelToCoords(sf::Mouse::getPosition(*gameengine->Gamewindow), this->view);

	while (gameengine->Gamewindow->pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			gameengine->Gamewindow->close();
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
				if (getClickedItem(mousePos) == "start_game")       this->startGame();
			}
			break;
		}
	}
}

GameStateSelect::GameStateSelect(Gameengine* game) {
	this->gameengine = game;
	float zoom = 1.0f; // No zoom

	sf::Vector2f pos = sf::Vector2f(game->Gamewindow->getSize());
	this->view.setSize(pos);
	this->view.zoom(zoom);

	// Get centre
	pos *= 0.5f;
	this->view.setCenter(pos * zoom);

	// Set Graphics Options
	GameStateSelect::startButton = sf::RectangleShape(sf::Vector2f(200.0f, 32.0f));
	GameStateSelect::startButton.setFillColor(sf::Color::White);
	GameStateSelect::startButton.setOutlineColor(sf::Color(200, 200, 200));
	GameStateSelect::startButton.setOutlineThickness(2.0f);
	GameStateSelect::startButton.setPosition(sf::Vector2f(100.0f, 184.0f));

	GameStateSelect::optionButton = sf::RectangleShape(sf::Vector2f(200.0f, 32.0f));
	GameStateSelect::optionButton.setFillColor(sf::Color::White);
	GameStateSelect::optionButton.setOutlineColor(sf::Color(200, 200, 200));
	GameStateSelect::optionButton.setOutlineThickness(2.0f);
	GameStateSelect::optionButton.setPosition(sf::Vector2f(100.0f, 224.0f));

	GameStateSelect::exitButton = sf::RectangleShape(sf::Vector2f(200.0f, 32.0f));
	GameStateSelect::exitButton.setFillColor(sf::Color::White);
	GameStateSelect::exitButton.setOutlineColor(sf::Color(200, 200, 200));
	GameStateSelect::exitButton.setOutlineThickness(2.0f);
	GameStateSelect::exitButton.setPosition(sf::Vector2f(100.0f, 264.0f));

	// test
	if (!font.loadFromFile("arial.ttf"))
		std::cout << "Can't find font";

	GameStateSelect::startbuttontext.setFont(font);
	GameStateSelect::startbuttontext.setString("Level 1");
	GameStateSelect::startbuttontext.setCharacterSize(20);
	GameStateSelect::startbuttontext.setColor(sf::Color::Red);
	GameStateSelect::startbuttontext.setPosition(sf::Vector2f(100.0f, 184.0f));

	GameStateSelect::optionbuttontext.setFont(font);
	GameStateSelect::optionbuttontext.setString("Level 2");
	GameStateSelect::optionbuttontext.setCharacterSize(20);
	GameStateSelect::optionbuttontext.setColor(sf::Color::Red);
	GameStateSelect::optionbuttontext.setPosition(sf::Vector2f(100.0f, 224.0f));

	GameStateSelect::exitbuttontext.setFont(font);
	GameStateSelect::exitbuttontext.setString("Level 3");
	GameStateSelect::exitbuttontext.setCharacterSize(20);
	GameStateSelect::exitbuttontext.setColor(sf::Color::Red);
	GameStateSelect::exitbuttontext.setPosition(sf::Vector2f(100.0f, 264.0f));

}