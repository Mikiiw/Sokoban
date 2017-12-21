#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
	//sf::RenderWindow window(sf::VideoMode(1280, 720), "Title");

	//sf::CircleShape shape(200.0f);
	//shape.setFillColor(sf::Color::Blue);
	//while (window.isOpen()) {
	//	window.draw(shape);
	//	window.display();
	//}
	//return 0;

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!", sf::Style::Close | sf::Style::Resize);
//Creates a frame of our window

	while (window.isOpen())
	{
		sf::Event evnt;
		//Allows our frames to use events
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				std::cout << evnt.size.width << evnt.size.height << std::endl;
			}
		}
	}
	return 0;
}