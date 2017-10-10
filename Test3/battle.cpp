#include "battle.h"
#include <iostream>
#include <conio.h>

Battle::Battle(Character* _ch1, Character* _ch2) : ch1(_ch1), ch2(_ch2){
	
}

Battle::~Battle() {
	std::cout << "KONIEC WALKI..\n";
}

void Battle::fight() {
	std::cout << "****************************   WALKA   ***********************\n";
	//while ((ch1->curHP()) && (ch2->curHP()) >= 0) {
		int dmg = ch1->getDamage();
		std::cout << ch1->getName() << " " << ch1->curHP() << "\n";
		std::cout << "Obrazenia: " << dmg << "\n";
		ch2->setCurHP(dmg);
		std::cout << ch2->getName() << " " << ch2->curHP() << "\n";
		//_getch();
	//}
}

