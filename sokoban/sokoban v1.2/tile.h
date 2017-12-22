#include <iostream>

class tile {
private:
	float width;
	float height;
	int type;

public:
	tile(int width, int height, int type);
	~tile();
	
	void tile::setwidth(int input);
	float tile::getwidth();

	void tile::setheight(int input);
	float tile::getheight();

};