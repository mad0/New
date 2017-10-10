#pragma once
#include "character.h"

class Player : public Character {
public:
	const std::string& getName();
	int getLevel();
	Player(const std::string&, int, int, int, int);
	virtual ~Player();
};
