#pragma once
#include "character.h"
#include <memory>

class Battle {
private:
	Character* ch1;
	std::shared_ptr<Character> ch2;

public:
	void fight();
	Battle(Character*, std::shared_ptr<Character>);
	~Battle();
};