#include <SFML/Graphics.hpp>
#include <iostream>


int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Title");

	sf::CircleShape shape(200.0f);
	shape.setFillColor(sf::Color::Blue);
	while (window.isOpen()) {
		window.draw(shape);
		window.display();
	}
	return 0;

}