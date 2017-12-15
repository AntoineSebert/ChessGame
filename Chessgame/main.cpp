/**
	\author Antoine "Anthony" Sébert
	\date 04/11/2017
	\brief main function
*/

#include "header.h"

int main(int argc, char *argv[]) {
	initializeGlut(argc, argv);
	glutReshapeFunc(reshape);

	Game* game = &Game::getInstance();
	game->initialize();

	glutMainLoop();
	return 0;
}