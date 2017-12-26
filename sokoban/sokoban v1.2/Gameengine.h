#ifndef _GAMEENGINE_H
#define _GAMEENGINE_H

#include <SFML/Graphics.hpp>
#include <vector>

class Gameengine {
private:
	sf::RenderWindow* Gamewindow;
	sf::RectangleShape Player;
	std::vector<sf::RectangleShape> tilelist;


public:
	Gameengine();
	~Gameengine();

	void initialise();
	void createPlayer();
	void loop();
	void drawMap();

};

#endif