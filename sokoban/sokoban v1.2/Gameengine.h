#ifndef _GAME_ENGINE_H
#define _GAME_ENGINE_H

#include <SFML/Graphics.hpp>
#include <stack>

class GameState;

class Gameengine {
private:
	


public:
	// Handles stack of game states
	std::stack<GameState*> states;
	// Handles GUI window
	sf::RenderWindow* Gamewindow;

	Gameengine();
	~Gameengine();

	void pushState(GameState* state);
	void popState();
	void changeState(GameState* state);
	GameState* peekState();
	void Gameengine::getPeekstate();

	void loop();

};

#endif