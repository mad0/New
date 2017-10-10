#pragma once
#include <string>

class Character {
protected:
	std::string name;
	int level, cur_hp, max_hp, dmgL, dmgH;
public:
	virtual const std::string& getName()=0;
	virtual int getLevel()=0;
	int getDamage();
	void setCurHP(int);
	int maxHP();
	int curHP();
	Character(const std::string&, int, int, int, int);
	virtual ~Character();
	
};