#include "map.h"
#include <iostream>

Map::Map(const std::string& map_name, int min_level, int max_level) :map_name(map_name), min_lvl(min_level), max_lvl(max_level) {
	std::cout << "LOAD MAP: " << map_name << "                MOBS LEVEL: " << min_lvl << "-" << max_lvl << "\n\n";
}

Map::~Map() {
	std::cout << "DELETE MAP: " << map_name << "              MOBS LEVEL: " << min_lvl << "-" << max_lvl << "\n";
}

const std::string& Map::mapName() {
	return map_name;
};