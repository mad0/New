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
	target.draw(lines);
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
	int f = 0;
	while (grid != 0) {
		bool coll = false;
		int rx = std::rand() % 7 + 0;
		int ry = std::rand() % 4 + 0;
		sf::Vector2f pos(x[rx], y[ry]);
		for (auto it = spriteMap.begin(); it != spriteMap.end(); it++) {
			if (it->getPosition() == pos) {
				std::cout << "POWTARZA SIE!!!\n";
				coll = true;
				f++;
			}
		}
			if (!coll) {
				sf::Sprite sp;
				sp.setTexture(tex);
				sp.setPosition(pos);
				spriteMap.push_back(sp);
				grid--;
				std::cout << "ILOSC SPRITOW W KONTENERZE:" << spriteMap.size() << "\n";
			}
	}
	std::cout << f << "\n";

		lines.setPrimitiveType(sf::LinesStrip);
		lines.resize(7);
		lines[0].position = sf::Vector2f(spriteMap[0].getGlobalBounds().left, spriteMap[0].getGlobalBounds().top);
		lines[1].position = sf::Vector2f(spriteMap[1].getGlobalBounds().left, spriteMap[1].getGlobalBounds().top);
		lines[2].position = sf::Vector2f(spriteMap[2].getGlobalBounds().left, spriteMap[2].getGlobalBounds().top);
		lines[3].position = sf::Vector2f(spriteMap[3].getGlobalBounds().left, spriteMap[3].getGlobalBounds().top);
		lines[4].position = sf::Vector2f(spriteMap[4].getGlobalBounds().left, spriteMap[4].getGlobalBounds().top);
		lines[5].position = sf::Vector2f(spriteMap[5].getGlobalBounds().left, spriteMap[5].getGlobalBounds().top);


	//}
}
