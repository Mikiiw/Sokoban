#ifndef _GAMEENGINE_H
#define _GAMEENGINE_H

#include <SFML/Graphics.hpp>
#include <stack>

class GameState;

class Gameengine {
private:
	


public:
	std::stack<GameState*> states;
	sf::RenderWindow* Gamewindow;

	Gameengine();
	~Gameengine();

	void pushState(GameState* state);
	void popState();
	void changeState(GameState* state);
	GameState* peekState();

	void initialise();
	void loop();

};

#endif