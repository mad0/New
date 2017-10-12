#include "map.h"
#include <iostream>

Map::Map(const std::string& map_name, std::vector<std::shared_ptr<Mob>> creatures) :map_name(map_name), creatures(creatures) {
	std::cout << "LOAD MAP: " << map_name << "\n\n";
	
}
Map::~Map() {
	std::cout << "DELETE MAP: " << map_name <<"\n";
}

void Map::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	//for (auto& r : vertexMap)
		target.draw(vertexMap, states);

}
const std::string& Map::mapName() {
	return map_name;
};

void Map::mapGenerator(int grid) {
	//std::cout << vertexMap. .size();
	vertexMap.resize(4);
	vertexMap.setPrimitiveType(sf::Quads);
	//for (int x = 0; x < grid; x++) {
		//for (int y = 0; y < 4; y++) {
		
			//rtexMap.resize(grid * 4);
			//sf::Vertex* pik = &vertexMap[x][y];
			vertexMap[0].position = sf::Vector2f(100, 100);
			vertexMap[1].position = sf::Vector2f(190, 100);
			vertexMap[2].position = sf::Vector2f(190, 190);
			vertexMap[3].position = sf::Vector2f(100, 190);
			vertexMap[0].color = sf::Color::Red;
			std::cout << "okok\n";
		//}
	//}

}