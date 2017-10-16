#pragma once
#include <string>
#include <vector>
#include <memory>
#include "mob.h"
#include "SFML\Graphics.hpp"

class Map : public sf::Drawable {
private:
	sf::Texture tex;
	sf::VertexArray mapBorder;
	//std::vector<int> map;
	std::string map_name;
	std::vector<std::shared_ptr<Mob>> creatures;
	std::vector<sf::Sprite> spriteMap;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	Map(const std::string&, const std::vector<std::shared_ptr<Mob>>);
	~Map();
	const std::string& mapName();
	void mapGenerator(int);
};