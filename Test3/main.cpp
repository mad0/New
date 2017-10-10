#include <iostream>
#include <ctime>
#include "map.h"
#include "player.h"
#include "mob.h"
#include "battle.h"
#include "SFML\Graphics.hpp"

int main() {
	srand(time(0));
	bool play = true;
	Map *mapka= new Map("Home", 0, 0);
	Player *p1 = new Player("Majlek", 1, 500, 10, 16);
	Mob *m1= new Mob("Slon", 2, 180, 12, 18);
	Battle b(p1, m1);
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Gra Alpha 0.0.01");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(35);
	sf::Texture hp;
	sf::Texture hp1;
	sf::Texture hp2;
	hp.loadFromFile("gfx/hp.png");
	hp1.loadFromFile("gfx/hp1.png");
	hp2.loadFromFile("gfx/hp2.png");
	sf::Sprite hpS;
	sf::Sprite hpS1;
	sf::Sprite hpS2;
	hpS.setTexture(hp);
	hpS1.setTexture(hp1);
	hpS2.setTexture(hp2);
	//sprit.setPosition(sf::Vector2f(0, 0));
	//sprit.scale(sf::Vector2f(0.5f,0.5f));
	//sprit.setPosition(sf::Vector2f(150, 360));
	sf::Font font;
	font.loadFromFile("2.ttf");
	sf::Text text;
	text.setFont(font);
	text.setFillColor(sf::Color::Black);
	text.setString("Pocaluj mnie w dupe jesli nei wiesz o co chodzi");
	text.setCharacterSize(19);
	while (window.isOpen()) {
		sf::Event zdarz;
		while (window.pollEvent(zdarz)) {
			if (zdarz.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				//p1->setHP(10);
				int hp = (p1->curHP() / p1->maxHP());
				std::cout << hp << "\n";

				//hpS1.setScale(sf::Vector2f(f, 1));
				//hpS1.setTextureRect(sf::IntRect(0,0, p1->showHP(), 210));
				//if (p1->showHP() <= 0)
				//	std::cout << "SMIERC!\n";
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				//f = f + 10;
				//hpS1.setTextureRect(sf::IntRect(0, 0,f, 210));
			}
		}
		
		window.clear(sf::Color::Black);
		window.draw(text);
		window.draw(hpS2);
		window.draw(hpS1);
		window.draw(hpS);
		window.display();
	}

return 0;
}