#pragma once
#include "SFML\Graphics.hpp"
#include <vector>

class GUI {
private:
	sf::RenderWindow& window;
	std::string file;
	sf::Texture guiTexture;
	sf::Sprite guiSrite;

public:
	GUI(sf::RenderWindow&, const std::string&);
	~GUI();
	void guiPosition();
	void guiDraw();
	void guiTextRect(int);
};