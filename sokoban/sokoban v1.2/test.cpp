#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

#include "tile.h"
#include "Map.h"
#include "Gameengine.h"
#include "GameStateMenu.h"

int main() {
	//sf::RenderWindow window(sf::VideoMode(1280, 720), "Title");

	//sf::CircleShape shape(200.0f);
	//shape.setFillColor(sf::Color::Blue);
	//while (window.isOpen()) {
	//	window.draw(shape);
	//	window.display();
	//}
	//return 0;

	//test region
	tile* testtile = new tile(2, 2, 1);
	float value = testtile->getwidth();
	std::cout << value;

	//Engine loop
	Gameengine* sokobanengine = new Gameengine();
	sokobanengine->initialise();
	sokobanengine->pushState(new GameStateMenu(sokobanengine));
	sokobanengine->loop();

	//}
	return 0;
}