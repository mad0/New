#pragma once
#include <string>
#include <vector>
#include <memory>
#include "mob.h"

class Map {
private:
	std::string map_name;
	int min_lvl, max_lvl;

public:
	Map(const std::string&, const std::vector<std::unique_ptr<Mob>>);
	std::vector<std::unique_ptr<Mob>> creatures;
	~Map();
	const std::string& mapName();
};