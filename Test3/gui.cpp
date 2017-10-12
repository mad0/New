#include "gui.h"
#include <iostream>

GUI::GUI(sf::RenderWindow& _window, const std::string& _file) : window(_window), file(_file){
	std::cout << "Tworze GUI...\n";
	guiTexture.loadFromFile(file);
	guiSrite.setTexture(guiTexture);
}

GUI::~GUI() {
	std::cout << "NISZCZE GUI...\n";
}

void GUI::guiDraw() {
	window.draw(guiSrite);
}

void GUI::guiTextRect(float rect) {
	guiSrite.setTextureRect(sf::IntRect(0, 0, rect * 520, 210));
}