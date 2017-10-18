#include "map.h"
#include <iostream>
#include <cstdlib>
#include <string>

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
	fnt.loadFromFile("Gameplay.ttf");
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
	for (auto& r : txt)
		target.draw(r);
	
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
		lines.setPrimitiveType(sf::LinesStrip);
		lines.resize(11);
		
		for (int c = 0; c < 6; c++) {
			sf::Text tx;
			tx.setFont(fnt);
			tx.setCharacterSize(20);
			tx.setString(std::to_string(c + 1));
			tx.setPosition(spriteMap[c].getPosition().x + 25, spriteMap[c].getPosition().y + 20);
			txt.push_back(tx);
			lines[0].position = sf::Vector2f(spriteMap[0].getPosition().x + 25, spriteMap[0].getPosition().y + 25);
			lines[1].position = sf::Vector2f(spriteMap[0].getPosition().x + 25, spriteMap[1].getPosition().y + 25);
			lines[2].position = sf::Vector2f(spriteMap[1].getPosition().x + 25, spriteMap[1].getPosition().y + 25);
			lines[3].position = sf::Vector2f(spriteMap[1].getPosition().x + 25, spriteMap[2].getPosition().y + 25);
			lines[4].position = sf::Vector2f(spriteMap[2].getPosition().x + 25, spriteMap[2].getPosition().y + 25);
			lines[5].position = sf::Vector2f(spriteMap[2].getPosition().x + 25, spriteMap[3].getPosition().y + 25);
			lines[6].position = sf::Vector2f(spriteMap[3].getPosition().x + 25, spriteMap[3].getPosition().y + 25);
			lines[7].position = sf::Vector2f(spriteMap[3].getPosition().x + 25, spriteMap[4].getPosition().y + 25);
			lines[8].position = sf::Vector2f(spriteMap[4].getPosition().x + 25, spriteMap[4].getPosition().y + 25);
			lines[9].position = sf::Vector2f(spriteMap[4].getPosition().x + 25, spriteMap[5].getPosition().y + 25);
			lines[10].position = sf::Vector2f(spriteMap[5].getPosition().x + 25, spriteMap[5].getPosition().y + 25);
			//lines[5].position = sf::Vector2f(spriteMap[0].getPosition().x + 25, spriteMap[1].getPosition().y + 25);
		}
		
}			
