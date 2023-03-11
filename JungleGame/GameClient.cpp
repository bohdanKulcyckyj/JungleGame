#include "GameClient.h"

GameClient::GameClient(Level* l) {
	this->currentLevel = l;
}

GameClient::~GameClient() {
	delete this->currentLevel;
	this->currentLevel = nullptr;
}

void GameClient::run() {

}
