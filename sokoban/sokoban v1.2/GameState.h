#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "Gameengine.h"

class GameState {
public:
	Gameengine* gameengine;

	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void handleInput() = 0;
};

#endif /* GAME_STATE_H */