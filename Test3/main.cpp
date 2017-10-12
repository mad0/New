#include <iostream>
#include <ctime>
#include "map.h"
#include "player.h"
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
	//std::vector<GUI*> hp;
	//hp.push_back(new GUI(window, "gfx/bar0.png"));
	//hp.push_back(new GUI(window, "gfx/bar1.png"));
	//moby
	std::vector<std::shared_ptr<Mob>> mobs;
	mobs.emplace_back(new Mob("SLON", 1, 200, 10, 19));
	//map
	Map m("Mapa pierwsza", mobs);
	m.mapGenerator(1);
	//Player
	Player *p1 = new Player("Majlek", 1, 500, 1, 15);
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
			if (zdarz.type == sf::Event::Closed) {
				delete p1;
				window.close();
			}
				
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

		//if (mobs.size() > 0) {
		//	Battle b(p1, mobs[0]);
		//	b.fight();
		//}
		//else if (mobs[0]->curHP() <= 0) {
		//	mobs.erase(mobs.end());
		
		//draw
		window.clear(sf::Color::Black);
		//window.draw(text);
		window.draw(m);
		//for (auto& button : hp)
		//	button->guiDraw();
		window.display();
	}

return 0;
}