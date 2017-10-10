#include "player.h"
#include <iostream>

Player::Player(const std::string& _name, int _level, int _hp, int _dmgL, int _dmgH) : Character(_name, _level, _hp, _dmgL, _dmgH){
	std::cout << "Tworze playera....\n";
}
Player::~Player(){
	std::cout << "Niszcze playera....\n";
}
const std::string& Player::getName()
{
	return name;
}

int Player::getLevel()
{
	return level;
}
