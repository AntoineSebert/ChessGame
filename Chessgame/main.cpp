/*
	@author Antoine "Anthony" S�bert
	@creation_date 04/11/2017
	@description main function
*/

#include "header.h"

int main(int argc, char *argv[]) {

	Game* game = &Game::getInstance();
	game->initialize();
	game->getGameMode();
	game->getDifficulty();

	return 0;
}