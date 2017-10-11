#include <iostream>
#include <ctime>
#include "map.h"
#include "player.h"
#include "mob.h"
#include "battle.h"
#include "GUI.h"
#include "SFML\Graphics.hpp"
#include <vector>
#include <memory>

int main() {
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Gra Alpha 0.0.01");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(35);
	srand(time(0));
	bool play = true;
	//hp bar
	std::vector<std::unique_ptr<GUI>> hp;
	hp.emplace_back(new GUI(window, "gfx/bar0.png"));
	hp.emplace_back(new GUI(window, "gfx/bar1.png"));
	//moby
	std::vector<std::unique_ptr<Mob>> mobs;
	mobs.emplace_back(new Mob("SLON", 1, 200, 10, 19));
	//battle.push_back(m1);
	//Player
	Player *p1 = new Player("Majlek", 1, 500, 1, 50);
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
				std::cout << mobs[0]->curHP() << " " << mobs[0]->maxHP() << "\n";

			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				//f = f + 10;
				//hpS1.setTextureRect(sf::IntRect(0, 0,f, 210));
			}
		}
		//update
		float hh = (static_cast<float>(mobs[0]->curHP()) / static_cast<float>(mobs[0]->maxHP()));
		hp[1]->guiTextRect(hh);
		if (mobs.size() > 0) {
			Battle b(p1, mobs[0]);
			//b.fight();
		}
		//	float hp = (static_cast<float>(m1->curHP()) / static_cast<float>(m1->maxHP()));
			//hpS1.setTextureRect(sf::IntRect(0, 0, hp * 500, 210));
		//}
		//draw
		window.clear(sf::Color::Black);
		window.draw(text);
		for (auto& button : hp)
			button->guiDraw();
		window.display();
	}

return 0;
}