/*! \fn			int main(int argc, char *argv[])
	\author		Antoine "Anthony" Sébert
	\date		04/11/2017
	\brief		Program entry point.
	\details	Initialize GLUT and the game object, and holds the graphic interface loop.
	\param[in]	argc	parameters count
	\param[in]	argv	parameters
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