#pragma once
#include <string>
#include <vector>
#include <memory>
#include "mob.h"

class Map {
private:
	std::vector<int> map;
	std::string map_name;
	std::vector<std::shared_ptr<Mob>> creatures;
public:
	Map(const std::string&, const std::vector<std::shared_ptr<Mob>>);
	~Map();
	const std::string& mapName();
};