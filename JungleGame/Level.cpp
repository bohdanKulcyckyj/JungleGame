#include "Level.h"

Level::Level(int num, Background* l) {
	this->background = l;
	this->levelNumber = num;
}

Level::~Level() {
	delete this->background;
	this->background = nullptr;
}