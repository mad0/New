#pragma once
#include "character.h"
#include <iostream>
#include <cstdlib>

Character::Character(const std::string& _name, int _level, int _hp, int _dmgL, int _dmgH) : name(_name), level(_level), max_hp(_hp), dmgL(_dmgL), dmgH(_dmgH){
	cur_hp = max_hp;
}

Character::~Character() {
}

int Character::getDamage() {
	return (std::rand() % (dmgH - dmgL)) + dmgL;
}

void Character::setCurHP(int _dmg)
{
	cur_hp = cur_hp - _dmg;
}

int Character::curHP()
{
	return cur_hp;
}

int Character::maxHP() {
	return max_hp;
}
