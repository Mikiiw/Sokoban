#include <iostream>
#include <vector>

#include "Gameengine.h"
#include "GameState.h"
#include "Map.h"
#include <SFML/Graphics.hpp>
#include "GameStateMenu.h"

Gameengine::Gameengine() {
	// Default Renderwindow
	Gameengine::Gamewindow = new sf::RenderWindow(sf::VideoMode(400, 400), "Sokoban", sf::Style::Close | sf::Style::Resize);
	// Defaults Game Menu to top of engine
	pushState(new GameStateMenu(this));
	return;
}

/** ~Gameengine
* Destructor, remove all states from stack before end
*/
Gameengine::~Gameengine() {
	while (!this->states.empty()) popState();
	return;
}

/**** GAME STATE STACK ****/

/** Gameengine::pushState
 * Add state to state stack
 * @param GameState* state	State to push onto stack
 */
void Gameengine::pushState(GameState* state) {
	this->states.push(state);
	return;
}

/** Gameengine::popState
* Pop state from state stack
*/
void Gameengine::popState() {
	delete this->states.top();
	this->states.pop();
	return;
}

/** Gameengine::changeState
* Pop top state off (if exists) and replace with param
* @param GameState* state	State to replace top state with
*/
void Gameengine::changeState(GameState* state) {
	if (!this->states.empty())
		popState();
	pushState(state);
	return;
}

/** Gameengine::peekState
* Peek top state on stack, nullptr if empty
* @return GameState*	State on top of stack
*/
GameState* Gameengine::peekState() {
	if (this->states.empty()) return nullptr; // return nullptr if stack empty
	return this->states.top();
}

/**** /GAME STATE STACK ****/

void Gameengine::loop() {


	while (Gamewindow->isOpen())
	{
		// If state exists, update state & redraw window
		if (peekState() == nullptr) continue;
		peekState()->handleInput();
		peekState()->update();

		Gameengine::Gamewindow->clear(sf::Color::White);
		peekState()->draw();

	}
	return;
}