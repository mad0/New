#pragma once
#include "character.h"

class Mob : public Character {
private:

public:
	const std::string& getName();
	int getLevel();
	Mob(const std::string&, int, int, int, int);
	~Mob();
};
