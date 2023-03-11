#pragma once
#include "Level.h"

class GameClient
{
private:
	Level* currentLevel;
public:
	GameClient(Level* l);
	~GameClient();
	void run();
};

