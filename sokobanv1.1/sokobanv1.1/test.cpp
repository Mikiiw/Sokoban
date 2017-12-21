#include <SFML/Graphics.hpp>
#include <iostream>


int main() {
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Title");

	sf::CircleShape Circle(200.0f);
	Circle.setFillColor(sf::Color::Blue);
	while (window.isOpen()) {
		window.draw(Circle);
		window.display();
	}
	return 0;

}