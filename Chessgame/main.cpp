/*
	@author Antoine "Anthony" Sébert
	@creation_date 04/11/2017
	@description main function
*/

#include "header.h"

int main(int argc, char *argv[]) {
	initializeGlut(argc, argv);

	glutReshapeFunc(reshape);
	//InitGL();

	Game* game = &Game::getInstance();
	game->initialize();

	//system("pause");

	glutMainLoop();
	return 0;
}