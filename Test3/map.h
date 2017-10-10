#pragma once
#include <string>

class Map {
private:
	std::string map_name;
	int min_lvl, max_lvl;

public:
	Map(const std::string&, int, int);
	~Map();
	const std::string& mapName();
};