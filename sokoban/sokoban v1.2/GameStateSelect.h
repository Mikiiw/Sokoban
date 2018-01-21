#ifndef GAME_STATE_SELECT_H
#define GAME_STATE_SELECT_H

#include <SFML/Graphics.hpp>
#include <string>

#include "GameState.h"

class GameStateSelect : public GameState {
private:
	sf::View view;
	sf::RectangleShape startButton;
	sf::RectangleShape optionButton;
	sf::RectangleShape exitButton;
	sf::Text startbuttontext;
	sf::Text optionbuttontext;
	sf::Text exitbuttontext;
	sf::Font font;

	void startGame();

public:
	virtual void draw();
	virtual void update();
	virtual void handleInput();

	std::string getClickedItem(sf::Vector2f mousePos);
	void highlightItems(sf::Vector2f mousePos);

	GameStateSelect(Gameengine *game);
};

#endif /* GAME_STATE_MENU_H */
#pragma once
