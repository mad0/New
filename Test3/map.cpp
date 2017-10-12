#include "map.h"
#include <iostream>

Map::Map(const std::string& map_name, std::vector<std::shared_ptr<Mob>> creatures) :map_name(map_name), creatures(creatures) {
	std::cout << "LOAD MAP: " << map_name << "\n\n";
}
Map::~Map() {
	std::cout << "DELETE MAP: " << map_name <<"\n";
}

const std::string& Map::mapName() {
	return map_name;
};