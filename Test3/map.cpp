#include "map.h"
#include <iostream>
#include <cstdlib>

Map::Map(const std::string& map_name, std::vector<std::shared_ptr<Mob>> creatures) :map_name(map_name), creatures(creatures) {
	std::cout << "LOAD MAP: " << map_name << "\n\n";
	if (!tex.loadFromFile("gfx/border.png"))
		std::cout << "error\n";
	mapBorder.setPrimitiveType(sf::LinesStrip);
	mapBorder.resize(3);
	mapBorder[0].position = (sf::Vector2f(0, 200));
	mapBorder[1].position = (sf::Vector2f(350, 200));
	mapBorder[2].position = (sf::Vector2f(350, 0));
	std::cout << "Ile linii: " << mapBorder.getVertexCount() << "\n";
}
Map::~Map() {
	std::cout << "DELETE MAP: " << map_name <<"\n";
}

void Map::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	states.texture = &tex;
	
	for (auto& r : spriteMap)
		target.draw(r);
	target.draw(mapBorder);
}

const std::string& Map::mapName() {
	return map_name;
};

void Map::mapGenerator(int grid) {
	int x[8] = {0, 50, 100, 150, 200, 250, 300, 350};
	int y[5] = { 0, 50, 100, 150, 200};
	for (int z = 0; z < grid; z++) {
		int rx = std::rand() % 7 + 0;
		int ry = std::rand() % 4 + 0;
		sf::Vector2i pos(x[rx], y[ry]);
		std::vector<sf::Sprite>::iterator iter;
		
		std::cout << rx << " " << ry << "\n";
		sf::Sprite sp;
		sp.setTexture(tex);
		sp.setPosition(sf::Vector2f(x[rx], y[ry]));
		spriteMap.push_back(sp);
		for (auto it = spriteMap.begin(); it != spriteMap.end(); it++)
			std::cout << "COORDS x: " << it->getPosition().x << "\n";
	}
	
	std::cout << "ILOSC SPRITOW W KONTENERZE:" << spriteMap.size() << "\n";
}