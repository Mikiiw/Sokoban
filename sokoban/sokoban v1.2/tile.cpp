#include <iostream>
#include "tile.h"

tile::tile(int width, int height, int type){
	tile::width = width;
	tile::height = height;
	tile::type = type;
}

tile::~tile() {}

	
	void tile::setwidth(int input) {
		std::cout << "width set";
		width = input;
	}

	float tile::getwidth() {
		return width;
	}

	void tile::setheight(int input) {
		std::cout << "width set";
		height = input;
	}

	float tile::getheight() {
		return height;
	}
