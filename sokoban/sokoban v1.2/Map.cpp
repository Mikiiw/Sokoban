#include <iostream>
#include "tile.h"
#include "Map.h"

Map::Map() {}
Map::~Map() {}
void Map::drawmap(int x, int y, int value) {
	Map::tilelist[x][y] = value;
}
