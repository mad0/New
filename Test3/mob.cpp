#include "mob.h"
#include <iostream>

const std::string & Mob::getName()
{
	return name;
}

int Mob::getLevel()
{
	return level;
}

Mob::Mob(const std::string& _name, int _level, int _hp, int _dmgL, int _dmgH) : Character(_name, _level, _hp, _dmgL, _dmgH) {
	std::cout << "TWORZE MOBA...\n";
}

Mob::~Mob() {
	std::cout << "NISZCZE MOBA...\n";
}