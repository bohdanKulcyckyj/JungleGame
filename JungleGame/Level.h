#pragma once
#include "Background.h";

class Level
{
private:
	int levelNumber;
	Background* background;
public:
	Level(int num, Background* l);
	~Level();
};

