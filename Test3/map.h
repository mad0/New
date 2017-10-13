#pragma once
#include <string>
#include <vector>
#include <memory>
#include "mob.h"
#include "SFML\Graphics.hpp"

class Map : public sf::Drawable {
private:
	sf::Texture tex;
	sf::Sprite sp;
	std::vector<int> map;
	std::string map_name;
	std::vector<std::shared_ptr<Mob>> creatures;
	std::vector<sf::Sprite> spriteMap;
	std::vector<sf::Vector2f> positions;
	enum Direction {
		LEFT = 1,
		RIGHT = 2,
		UP = 3,
		DOWN = 4
	};
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	Map(const std::string&, const std::vector<std::shared_ptr<Mob>>);
	~Map();
	const std::string& mapName();
	void mapGenerator(int);
};