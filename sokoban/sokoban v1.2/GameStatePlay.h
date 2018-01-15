#ifndef GAME_STATE_PLAY_H
#define GAME_START_PLAY_H

#include <SFML/Graphics.hpp>
#include <vector>

#include "GameState.h"

class GameStatePlay : public GameState {
private:
	sf::View view;
	std::vector<sf::RectangleShape> tilelist;
	sf::RectangleShape Player;

	void createPlayer();
	void drawMap();

public:

	virtual void draw();
	virtual void update();
	virtual void handleInput();
	virtual void handleMovement(sf::Event event);

	GameStatePlay(Gameengine *game);
};

#endif /* GAME_STATE_PLAY_H */
