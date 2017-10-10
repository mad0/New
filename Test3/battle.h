#pragma once
#include "character.h"

class Battle {
private:
	Character* ch1;
	Character* ch2;
public:
	void fight();
	Battle(Character*, Character*);
	~Battle();
};