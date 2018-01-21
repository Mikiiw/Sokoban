#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameStatePlay.h"
#include "GameState.h"

int tileSize = 50.0f;
int mapWidth = 8;
int mapHeight = 8;

void GameStatePlay::createPlayer() {
	GameStatePlay::Player = sf::RectangleShape(sf::Vector2f(tileSize, tileSize));
	GameStatePlay::Player.setFillColor(sf::Color::White);
	GameStatePlay::Player.setPosition(150.0f, 150.0f);
	playertexture.loadFromFile("PNG/Character4.png");
	GameStatePlay::Player.setTexture(&playertexture);

}

void GameStatePlay::drawMap() {
	//Only draws a fixed map as of right now, its going to pull from multiple maps
	tilelist = std::vector<sf::RectangleShape>(64);

	GameStatePlay::walltexture.loadFromFile("PNG/Wall_Black.png");
	GameStatePlay::groundtexture.loadFromFile("PNG/GroundGravel_Concrete.png");


	//Map* level1 = new Map();
<<<<<<< HEAD
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			tilelist[(8 * i) + j] = sf::RectangleShape(sf::Vector2f(tileSize, tileSize));
			tilelist[(8 * i) + j].setPosition(i * tileSize, j * tileSize);
			//Wall Pattern
			if (i == 0 || i == 7 || j == 0 || j == 7) 
				tilelist[(8 * i) + j].setTexture(&walltexture);
			else
				tilelist[(8 * i) + j].setTexture(&groundtexture);
=======
	for (int i = 0; i < mapWidth; i++)
		for (int j = 0; j < mapHeight; j++) {
			tilelist[(mapWidth * i) + j] = sf::RectangleShape(sf::Vector2f(tileSize, tileSize));
			tilelist[(mapWidth * i) + j].setPosition(i * tileSize, j * tileSize);
			//Stripe Pattern
			if ((j + i) % 2 == 0)
				tilelist[(mapWidth * i) + j].setFillColor(sf::Color::Blue);
			else
				tilelist[(mapWidth * i) + j].setFillColor(sf::Color::Green);
>>>>>>> b71e8eeda222afd9148882c4ebebf5c5730b4093
		}


}

void GameStatePlay::draw() {
	/*reset screen*/
	gameengine->Gamewindow->clear();

	// Set this as current view
	gameengine->Gamewindow->setView(this->view);

	//color tiles
	for (int i = 0; i < (mapWidth * mapHeight); i++) {
		gameengine->Gamewindow->draw(tilelist[i]);
	}
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

bool GameStatePlay::checkMove(int move){
	int i;
	int j;
	switch (move) {
	case 1:
		i = (Player.getPosition().x / tileSize) - 1;
		j = (Player.getPosition().y / tileSize);
		playertexture.loadFromFile("PNG/Character1.png");
		if (tilelist[(8 * i) + j].getTexture() == &walltexture) {
			std::cout << "Its a wall dumbass";
			return false;
		}else
//		std::cout << "moveleft";
		break;
	case 2:
		i = (Player.getPosition().x / tileSize);
		j = (Player.getPosition().y / tileSize) - 1;
		playertexture.loadFromFile("PNG/Character7.png");
		if (tilelist[(8 * i) + j].getTexture() == &walltexture) {
			std::cout << "Its a wall dumbass";
			return false;
		}
		else
			//		std::cout << "moveup";
			break;
	case 3:
		i = (Player.getPosition().x / tileSize) + 1;
		j = (Player.getPosition().y / tileSize);
		playertexture.loadFromFile("PNG/Character2.png");
		if (tilelist[(8 * i) + j].getTexture() == &walltexture) {
			std::cout << "Its a wall dumbass";
			return false;
		}
		else
			//		std::cout << "moveright";
			break;
	case 4:
		i = (Player.getPosition().x / tileSize);
		j = (Player.getPosition().y / tileSize) + 1;
		playertexture.loadFromFile("PNG/Character4.png");
		if (tilelist[(8 * i) + j].getTexture() == &walltexture) {
			std::cout << "Its a wall dumbass";
			return false;
		}
		else
			//		std::cout << "movedown";
			break;
	}
	return true;
}

void GameStatePlay::moveBox()
{
}

void GameStatePlay::handleMovement(sf::Event event) {
	switch (event.key.code) {
<<<<<<< HEAD
	case sf::Keyboard::A:
		if (checkMove(1) == false) {}
		else
			Player.move(-1 * tileSize, 0.0f);
		break;
	case sf::Keyboard::W:
		if (checkMove(2) == false) {}
		else
		Player.move(0.0f, -1 * tileSize);
		break;
	case sf::Keyboard::D:
		if (checkMove(3) == false) {}
		else
			Player.move(tileSize, 0.0f);
		break;
	case sf::Keyboard::S:
		if (checkMove(4) == false) {}
		else
			Player.move(0.0f, tileSize);
		break;
=======
		case sf::Keyboard::A:
		case sf::Keyboard::Left:
			if (Player.getPosition().x > 0)
				Player.move(-1 * tileSize, 0.0f);
			break;
		case sf::Keyboard::W:
		case sf::Keyboard::Up:
			if (Player.getPosition().y > 0)
				Player.move(0.0f, -1 * tileSize);
			break;
		case sf::Keyboard::D:
		case sf::Keyboard::Right:
			if (Player.getPosition().x + tileSize < mapWidth * tileSize)
				Player.move(tileSize, 0.0f);
			break;
		case sf::Keyboard::S:
		case sf::Keyboard::Down:
			if (Player.getPosition().y + tileSize < mapHeight * tileSize)
				Player.move(0.0f, tileSize);
			break;
>>>>>>> b71e8eeda222afd9148882c4ebebf5c5730b4093
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
	drawMap();
}