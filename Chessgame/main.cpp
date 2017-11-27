/*
	@author Antoine "Anthony" Sébert
	@creation_date 04/11/2017
	@description main function
*/

#include "header.h"

void displayMe(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.5, 0.0);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.0, 0.5);
	glEnd();
	glFlush();
}

int main(int argc, char *argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(500, 500);
	glutCreateWindow("test");
	glutDisplayFunc(displayMe);
	glutMainLoop();

	Game* game = &Game::getInstance();
	game->initialize();

	system("pause");

	return 0;
}