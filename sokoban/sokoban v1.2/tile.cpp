#include <iostream>
#include "tile.h"

tile::tile(int type){
	tile::type = type;
}

tile::~tile() {}

void tile::setType(int number) {
	tile::type = number;
	return;
}
