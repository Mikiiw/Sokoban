#include <iostream>

class tile {
private:
	float width;
	float height;
	int type;

public:
	tile();
	~tile();
	
	void tile::setwidth(int input);
	float tile::getwidth();

	void tile::setheight(int input);
	float tile::getheight();

};