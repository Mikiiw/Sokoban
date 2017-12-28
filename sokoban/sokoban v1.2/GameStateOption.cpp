#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#include "GameStateMenu.h"
#include "GameState.h"
#include "GameStateOption.h"

void GameStateOption::goBack() {
	//TODO: change this shit, this is not how you change states
	gameengine->pushState(new GameStateMenu(this->gameengine));
	//gameengine->changeState(new GameStateMenu(this->gameengine));
	return;
}

void GameStateOption::draw() {
	gameengine->Gamewindow->clear(sf::Color::Black);
	gameengine->Gamewindow->setView(this->view);

	gameengine->Gamewindow->draw(GameStateOption::optionButton);
	gameengine->Gamewindow->display();

	return;
}

void GameStateOption::update() {

}

void GameStateOption::highlightItems(sf::Vector2f mousePos) {
	// TODO: Extend for multiple menu items

	if (this->optionButton.getGlobalBounds().contains(mousePos)) {
		this->optionButton.setFillColor(sf::Color(100, 250, 250));
	}
	else {
		this->optionButton.setFillColor(sf::Color(255, 255, 255));
	}

	return;
}

std::string GameStateOption::getClickedItem(sf::Vector2f mousePos) {
	// TODO: Extend for multiple menu items

	if (this->optionButton.getGlobalBounds().contains(mousePos)) {
		return "back";
	}
	return "";
}

void GameStateOption::handleInput() {
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
				if (getClickedItem(mousePos) == "back") this->goBack();
			}
			break;
		}
	}
}

GameStateOption::GameStateOption(Gameengine* game) {
	this->gameengine = game;
	float zoom = 1.0f; // No zoom

	sf::Vector2f pos = sf::Vector2f(game->Gamewindow->getSize());
	this->view.setSize(pos);
	this->view.zoom(zoom);

	// Get centre
	pos *= 0.5f;
	this->view.setCenter(pos * zoom);

	// Set Graphics Options
	GameStateOption::optionButton = sf::RectangleShape(sf::Vector2f(50.0f, 32.0f));
	GameStateOption::optionButton.setFillColor(sf::Color::White);
	GameStateOption::optionButton.setOutlineColor(sf::Color(200, 200, 200));
	GameStateOption::optionButton.setOutlineThickness(2.0f);
	GameStateOption::optionButton.setPosition(sf::Vector2f(20.0f, 350.0f));

	// test
	if (!font.loadFromFile("arial.ttf"))
		std::cout << "Can't find font";


}