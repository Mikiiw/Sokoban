class Map {
private:
	int tilelist[4][4] = { 0, 0, 0, 0,
						   0, 0, 0, 0,
						   0, 0, 0, 0,
						   0, 0, 0, 0 };
	int width;
	int height;

public:
	Map();
	~Map();

	void Map::drawmap(int x, int y, int value);


};
