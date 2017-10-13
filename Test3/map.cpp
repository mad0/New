#include "map.h"
#include <iostream>

Map::Map(const std::string& map_name, std::vector<std::shared_ptr<Mob>> creatures) :map_name(map_name), creatures(creatures) {
	std::cout << "LOAD MAP: " << map_name << "\n\n";
	if (!tex.loadFromFile("gfx/border.png"))
		std::cout << "error\n";
	sp.setTexture(tex);
	sp.setColor(sf::Color::Red);
	sp.setPosition(sf::Vector2f(300, 300));
	spriteMap.push_back(sp);
}
Map::~Map() {
	std::cout << "DELETE MAP: " << map_name <<"\n";
}

void Map::draw(sf::RenderTarget & target, sf::RenderStates states) const {
	states.texture = &tex;
	for (auto& r : spriteMap)
		target.draw(r);

}
const std::string& Map::mapName() {
	return map_name;
};

void Map::mapGenerator(int grid) {
	for (int z = 0; z < grid-1; z++) {
		sf::Vector2f actPos = spriteMap[z].getPosition();
		//sp.setTexture(tex);
		Direction dir[4] = { LEFT, RIGHT, UP, DOWN };
		int r = (std::rand() % 4) +0;
		std::cout << r << "\n";
		switch (Direction(dir[r])) {
		case LEFT:
			//sf::Vector2f nextPos(actPos.x-50, actPos.y);
			//if ( (nextPos.x<0 || nextPos.y<0) )
			//	std::cout<<"<0\n";
			//sp.setPosition(;
			break;
		case RIGHT:
			sp.setPosition(actPos.x + 50, actPos.y);
			break;
		case UP:
			sp.setPosition(actPos.x, actPos.y-50);
			break;
		case DOWN:
			sp.setPosition(actPos.x, actPos.y+50);
			break;
		}
		//std::cout << startPos[dir] << "\n";
		
		
		//sf::Vector2f pos(x*55, y*50);
		spriteMap.push_back(sp);
	}
}