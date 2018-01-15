
#ifndef GAME_STATE_OPTION_H
#define GAME_START_OPTION_H

#include <SFML/Graphics.hpp>
#include <string>

#include "GameState.h"

class GameStateOption : public GameState {
private:
	sf::View view;
	sf::Font font;
	sf::RectangleShape backButton;

	void goBack();

public:

	virtual void draw();
	virtual void update();
	virtual void handleInput();


	std::string getClickedItem(sf::Vector2f mousePos);
	void highlightItems(sf::Vector2f mousePos);
	GameStateOption(Gameengine *game);
};

#endif /* GAME_STATE_OPTION_H */
