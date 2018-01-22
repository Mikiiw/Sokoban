#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameStatePlay.h"
#include "GameState.h"

int tileSize = 50.0f;
int mapWidth = 8;
int mapHeight = 8;

void GameStatePlay::createPlayer() {
	GameStatePlay::Player = sf::RectangleShape(sf::Vector2f(tileSize, tileSize));
	GameStatePlay::Player.setPosition(150.0f, 150.0f);
	playertexture.loadFromFile("PNG/Character4.png");
	GameStatePlay::Player.setTexture(&playertexture);

	return;
}

void GameStatePlay::createBox() {
	GameStatePlay::Box = sf::RectangleShape(sf::Vector2f(tileSize, tileSize));
	GameStatePlay::Box.setPosition(200.0f, 200.0f);
	boxtexture.loadFromFile("PNG/Crate_Beige.png");
	GameStatePlay::Box.setTexture(&boxtexture);

	return;
}

void GameStatePlay::drawMap() {
	//Only draws a fixed map as of right now, its going to pull from multiple maps
	tilelist = std::vector<sf::RectangleShape>(64);

	GameStatePlay::walltexture.loadFromFile("PNG/Wall_Black.png");
	GameStatePlay::groundtexture.loadFromFile("PNG/GroundGravel_Concrete.png");


	//Map* level1 = new Map();
	for (int i = 0; i < mapWidth; i++)
		for (int j = 0; j < mapHeight; j++) {
			tilelist[(8 * i) + j] = sf::RectangleShape(sf::Vector2f(tileSize, tileSize));
			tilelist[(8 * i) + j].setPosition(i * tileSize, j * tileSize);
			//Wall Pattern
			if (i == 0 || i == 7 || j == 0 || j == 7) 
				tilelist[(8 * i) + j].setTexture(&walltexture);
			else
				tilelist[(8 * i) + j].setTexture(&groundtexture);
		}


}

void GameStatePlay::draw() {
	/*reset screen*/
	gameengine->Gamewindow->clear();

	// Set this as current view
	gameengine->Gamewindow->setView(this->view);

	//color tiles
	for (int i = 0; i < (mapWidth*mapHeight); i++) {
		gameengine->Gamewindow->draw(tilelist[i]);
	}
	gameengine->Gamewindow->draw(GameStatePlay::Box);
	gameengine->Gamewindow->draw(GameStatePlay::Player);
	gameengine->Gamewindow->display();
}

void GameStatePlay::update() {
	
}

void GameStatePlay::handleInput() {
	sf::Event event;

	while (gameengine->Gamewindow->pollEvent(event)) {
		switch (event.type) {
			case sf::Event::Closed:
				gameengine->Gamewindow->close();
				break;
			case sf::Event::Resized:
				std::cout << "New Width: " << event.size.width << " New Height: " << event.size.height << std::endl;
				break;
			case sf::Event::TextEntered:
				if (event.text.unicode < 128) {
					printf("%c", event.text.unicode);
				}
				break;
			case sf::Event::KeyReleased:
				handleMovement(event);
				break;
		}
	}
}

bool GameStatePlay::checkPlayer(int move){
	int i;
	int j;
	switch (move) {
	case 1:
		i = (Player.getPosition().x / tileSize) - 1;
		j = (Player.getPosition().y / tileSize);
		if (tilelist[(8 * i) + j].getTexture() == &walltexture) {
			std::cout << "Its a wall dumbass";
			return false;
		}else if (Box.getPosition().x / tileSize == i & Box.getPosition().y / tileSize == j) {
			std::cout << "Box blocking way";
			return false;
		}
		break;
	case 2:
		i = (Player.getPosition().x / tileSize);
		j = (Player.getPosition().y / tileSize) - 1;
		if (tilelist[(8 * i) + j].getTexture() == &walltexture) {
			std::cout << "Its a wall dumbass";
			return false;
		}else if (Box.getPosition().x / tileSize == i & Box.getPosition().y / tileSize == j) {
			std::cout << "Box blocking way";
			return false;
		}
			break;
	case 3:
		i = (Player.getPosition().x / tileSize) + 1;
		j = (Player.getPosition().y / tileSize);
		if (tilelist[(8 * i) + j].getTexture() == &walltexture) {
			std::cout << "Its a wall dumbass";
			return false;
		}else if (Box.getPosition().x / tileSize == i & Box.getPosition().y / tileSize == j) {
			std::cout << "Box blocking way";
			return false;
		}
			break;
	case 4:
		i = (Player.getPosition().x / tileSize);
		j = (Player.getPosition().y / tileSize) + 1;
		if (tilelist[(8 * i) + j].getTexture() == &walltexture) {
			std::cout << "Its a wall dumbass";
			return false;
		}else if (Box.getPosition().x / tileSize == i & Box.getPosition().y / tileSize == j) {
			std::cout << "Box blocking way";
			return false;
		}
		break;
	}
	return true;
}

bool GameStatePlay::checkBox(int move) {
	int i;
	int j;
	switch (move) {
	case 1:
		i = (Player.getPosition().x / tileSize) - 1;
		j = (Player.getPosition().y / tileSize);
		if (Box.getPosition().x / tileSize == i & Box.getPosition().y / tileSize == j) {
			std::cout << "Its a box";
			i = (Box.getPosition().x / tileSize) - 1;
			j = (Box.getPosition().y / tileSize);
			if (tilelist[(8 * i) + j].getTexture() == &walltexture) {
				std::cout << "Wall blocking box";
				return false;			
			}
			return true;
		}
		else
			//		std::cout << "moveleft";
			break;
	case 2:
		i = (Player.getPosition().x / tileSize);
		j = (Player.getPosition().y / tileSize) - 1;
		if (Box.getPosition().x / tileSize == i & Box.getPosition().y / tileSize == j) {
			std::cout << "Its a box";
			i = (Box.getPosition().x / tileSize);
			j = (Box.getPosition().y / tileSize) - 1;
			if (tilelist[(8 * i) + j].getTexture() == &walltexture) {
				std::cout << "Wall blocking box";
				return false;
			}
			return true;
		}
		else
			//		std::cout << "moveup";
			break;
	case 3:
		i = (Player.getPosition().x / tileSize) + 1;
		j = (Player.getPosition().y / tileSize);
		if (Box.getPosition().x / tileSize == i & Box.getPosition().y / tileSize == j) {
			std::cout << "Its a box";
			i = (Box.getPosition().x / tileSize) + 1;
			j = (Box.getPosition().y / tileSize);
			if (tilelist[(8 * i) + j].getTexture() == &walltexture) {
				std::cout << "Wall blocking box";
				return false;
			}
			return true;
		}
		else
			//		std::cout << "moveright";
			break;
	case 4:
		i = (Player.getPosition().x / tileSize);
		j = (Player.getPosition().y / tileSize) + 1;
		if (Box.getPosition().x / tileSize == i & Box.getPosition().y / tileSize == j) {
			std::cout << "Its a box";
			i = (Box.getPosition().x / tileSize);
			j = (Box.getPosition().y / tileSize) + 1;
			if (tilelist[(8 * i) + j].getTexture() == &walltexture) {
				std::cout << "Wall blocking box";
				return false;
			}
			return true;
		}
		else
			//		std::cout << "movedown";
			break;
	}
	return false;

}

void GameStatePlay::handleMovement(sf::Event event) {
	switch (event.key.code) {
	case sf::Keyboard::A:
		if (checkBox(1) == true) {
			playertexture.loadFromFile("PNG/Character1.png");
			Box.move(-1 * tileSize, 0.0f);
			Player.move(-1 * tileSize, 0.0f);
		}
		else if (checkPlayer(1) == true) {
			Player.move(-1 * tileSize, 0.0f);
			playertexture.loadFromFile("PNG/Character1.png");
		}
		break;
	case sf::Keyboard::W:
		if (checkBox(2) == true) {
			playertexture.loadFromFile("PNG/Character7.png");
			Box.move(0.0f, -1 * tileSize);
			Player.move(0.0f, -1 * tileSize);
		}
		else if (checkPlayer(2) == true) {
			Player.move(0.0f, -1 * tileSize);
			playertexture.loadFromFile("PNG/Character7.png");
		}
		break;
	case sf::Keyboard::D:
		if (checkBox(3) == true) {
			playertexture.loadFromFile("PNG/Character2.png");
			Box.move(tileSize, 0.0f);
			Player.move(tileSize, 0.0f);
		}
		else if (checkPlayer(3) == true) {
			Player.move(tileSize, 0.0f);
			playertexture.loadFromFile("PNG/Character2.png");
		}
		break;
	case sf::Keyboard::S:
		if (checkBox(4) == true) {
			playertexture.loadFromFile("PNG/Character4.png");
			Box.move(0.0f, tileSize);
			Player.move(0.0f, tileSize);
		}
		else if (checkPlayer(4) == true){
			Player.move(0.0f, tileSize);
			playertexture.loadFromFile("PNG/Character4.png");
		}
		break;
	}
}

GameStatePlay::GameStatePlay(Gameengine* game) {
	this->gameengine = game;
	float zoom = 1.0f; // Zoom out to double size
	
	sf::Vector2f pos = sf::Vector2f(game->Gamewindow->getSize());
	this->view.setSize(pos);
	this->view.zoom(zoom);

	// Get centre
	pos *= 0.5f;
	this->view.setCenter(pos * zoom);

	createPlayer();
	createBox();
	drawMap();
}