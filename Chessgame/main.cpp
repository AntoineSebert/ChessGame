/*
	@author Antoine "Anthony" Sébert
	@creation_date 04/11/2017
	@description main function
*/

#include "header.h"

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Efface le frame buffer et le Z-buffer
	glMatrixMode(GL_MODELVIEW); //Choisit la matrice MODELVIEW
	glLoadIdentity(); //Réinitialise la matrice
	gluLookAt(0, 0, -10, 0, 0, 0, 0, 1, 0);
	glutSwapBuffers(); //Attention : pas SwapBuffers(DC) !
	glutPostRedisplay();
}

int main(int argc, char *argv[]) {
	initializeGlut(argc, argv);

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	//InitGL();

	//Game* game = &Game::getInstance();
	//game->initialize();

	//system("pause");

	glutMainLoop();
	return 0;
}