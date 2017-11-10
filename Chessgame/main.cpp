/*
	@author Antoine "Anthony" Sébert
	@creation_date 04/11/2017
	@description main function
*/

#include "header.h"

int main(int argc, char *argv[]) {

	Game* game = &Game::getInstance();
	game->initialize();

	system("pause");

	return 0;
}