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
	sf::RectangleShape Box;
	sf::Texture walltexture;
	sf::Texture playertexture;
	sf::Texture groundtexture;
	sf::Texture boxtexture;
	
	void createPlayer();
	void drawMap();
	bool checkPlayer(int move);
	bool checkBox(int move);
	void nextLevel();
	void createBox();


public:

	virtual void draw();
	virtual void update();
	virtual void handleInput();
	virtual void handleMovement(sf::Event event);

	GameStatePlay(Gameengine *game);
};

#endif /* GAME_STATE_PLAY_H */
