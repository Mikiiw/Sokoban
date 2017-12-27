#ifndef GAME_STATE_MENU_H
#define GAME_START_MENU_H

#include <SFML/Graphics.hpp>
#include <string>

#include "GameState.h"

class GameStateMenu : public GameState {
private:
	sf::View view;
	sf::RectangleShape startButton;

	void startGame();

public:
	virtual void draw();
	virtual void update();
	virtual void handleInput();

	std::string getClickedItem(sf::Vector2f mousePos);
	void highlightItems(sf::Vector2f mousePos);

	GameStateMenu(Gameengine *game);
};

#endif /* GAME_STATE_MENU_H */
