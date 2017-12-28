#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#include "GameStateMenu.h"
#include "GameStatePlay.h"
#include "GameStateOption.h"
#include "GameState.h"

void GameStateMenu::startGame() {
	gameengine->pushState(new GameStatePlay(this->gameengine));
	return;
}

void GameStateMenu::gotoOption() {
	gameengine->pushState(new GameStateOption(this->gameengine));
	return;
}

void GameStateMenu::draw() {
	gameengine->Gamewindow->clear(sf::Color::Black);
	gameengine->Gamewindow->setView(this->view);

	gameengine->Gamewindow->draw(GameStateMenu::startButton);
	gameengine->Gamewindow->draw(GameStateMenu::startbuttontext);
	gameengine->Gamewindow->draw(GameStateMenu::optionButton);
	gameengine->Gamewindow->draw(GameStateMenu::optionbuttontext);
	gameengine->Gamewindow->draw(GameStateMenu::exitButton);
	gameengine->Gamewindow->draw(GameStateMenu::exitbuttontext);
	gameengine->Gamewindow->display();

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
	
	if (this->startButton.getGlobalBounds().contains(mousePos)) 
		return "start_game";

	if (this->optionButton.getGlobalBounds().contains(mousePos)) 
		return "option";

	if (this->exitButton.getGlobalBounds().contains(mousePos))
		return "exit";
	
	return "";
}

void GameStateMenu::handleInput() {
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
					if (getClickedItem(mousePos) == "start_game") this->startGame();
					if (getClickedItem(mousePos) == "option")     this->gotoOption();
					if (getClickedItem(mousePos) == "exit")       gameengine->Gamewindow->close();
				}
				break;
		}
	}
}

GameStateMenu::GameStateMenu(Gameengine* game) {
	this->gameengine = game;
	float zoom = 1.0f; // No zoom

	sf::Vector2f pos = sf::Vector2f(game->Gamewindow->getSize());
	this->view.setSize(pos);
	this->view.zoom(zoom);

	// Get centre
	pos *= 0.5f;
	this->view.setCenter(pos * zoom);

	// Set Graphics Options
	GameStateMenu::startButton = sf::RectangleShape(sf::Vector2f(200.0f, 32.0f));
	GameStateMenu::startButton.setFillColor(sf::Color::White);
	GameStateMenu::startButton.setOutlineColor(sf::Color(200, 200, 200));
	GameStateMenu::startButton.setOutlineThickness(2.0f);
	GameStateMenu::startButton.setPosition(sf::Vector2f(100.0f, 184.0f));

	GameStateMenu::optionButton = sf::RectangleShape(sf::Vector2f(200.0f, 32.0f));
	GameStateMenu::optionButton.setFillColor(sf::Color::White);
	GameStateMenu::optionButton.setOutlineColor(sf::Color(200, 200, 200));
	GameStateMenu::optionButton.setOutlineThickness(2.0f);
	GameStateMenu::optionButton.setPosition(sf::Vector2f(100.0f, 224.0f));

	GameStateMenu::exitButton = sf::RectangleShape(sf::Vector2f(200.0f, 32.0f));
	GameStateMenu::exitButton.setFillColor(sf::Color::White);
	GameStateMenu::exitButton.setOutlineColor(sf::Color(200, 200, 200));
	GameStateMenu::exitButton.setOutlineThickness(2.0f);
	GameStateMenu::exitButton.setPosition(sf::Vector2f(100.0f, 264.0f));

	// test
	if (!font.loadFromFile("arial.ttf"))
		std::cout << "Can't find font";

	GameStateMenu::startbuttontext.setFont(font);
	GameStateMenu::startbuttontext.setString("Start Game");
	GameStateMenu::startbuttontext.setCharacterSize(20);
	GameStateMenu::startbuttontext.setColor(sf::Color::Red);
	GameStateMenu::startbuttontext.setPosition(sf::Vector2f(100.0f, 184.0f));

	GameStateMenu::optionbuttontext.setFont(font);
	GameStateMenu::optionbuttontext.setString("Options");
	GameStateMenu::optionbuttontext.setCharacterSize(20);
	GameStateMenu::optionbuttontext.setColor(sf::Color::Red);
	GameStateMenu::optionbuttontext.setPosition(sf::Vector2f(100.0f, 224.0f));

	GameStateMenu::exitbuttontext.setFont(font);
	GameStateMenu::exitbuttontext.setString("Exit");
	GameStateMenu::exitbuttontext.setCharacterSize(20);
	GameStateMenu::exitbuttontext.setColor(sf::Color::Red);
	GameStateMenu::exitbuttontext.setPosition(sf::Vector2f(100.0f, 264.0f));



}