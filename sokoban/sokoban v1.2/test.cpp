#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

#include "tile.h"
#include "Map.h"
#include "Gameengine.h"
#include "GameStateMenu.h"

void main() {
	//test region
	//tile* testtile = new tile(2, 2, 1);
	//float value = testtile->getwidth();
	//std::cout << value;

	//Engine loop
	Gameengine* sokobanengine = new Gameengine();
	//Renders GUI graphics
	sokobanengine->loop();

	return;
}