/*
	@author Antoine "Anthony" Sébert
	@creation_date 04/12/2017
	@description glut related functions & data
*/

#pragma once

#include <list>
#include <utility>

using namespace std;

// data
	const unsigned int WINDOW_WIDTH = 600;
	const unsigned int WINDOW_HEIGHT = 600;
	const char WINDOW_NAME[] = "1705851";

// functions
	// initialization
		void initializeViewPort() {
			gluOrtho2D(0.0, 50.0, 0.0, 50.0);
			glViewport(
				glutGet(GLUT_WINDOW_X),
				glutGet(GLUT_WINDOW_Y),
				glutGet(GLUT_WINDOW_WIDTH),
				glutGet(GLUT_WINDOW_HEIGHT)
			);
		}
		void initializeWindow() {
			glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
			glutInitWindowPosition(
				(glutGet(GLUT_SCREEN_WIDTH) - WINDOW_WIDTH) / 2,
				(glutGet(GLUT_SCREEN_HEIGHT) - WINDOW_HEIGHT) / 2
			);
			glutCreateWindow(WINDOW_NAME);
		}
		void initializeGlut(int argc, char *argv[]) {
			glutInit(&argc, argv);
			glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
			initializeWindow();
			initializeViewPort();
		}
	// event
		void reshape(int width, int height) {
			glViewport(0, 0, width, height);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(
				45,
				float(width) / float(height),
				0.1,
				100
			); //Pour les explications, lire le tutorial sur OGL et win
			glMatrixMode(GL_MODELVIEW); //Optionnel
		}
	// drawing
		// high level
			void drawDifficultyMenu() {

			}
		// medium level
		// low level
			void drawGeometric(list<tuple<int, int>> vertices) {
				switch (vertices.size()) {
					case 1:
						glBegin(GL_POINTS);
						break;
					case 2:
						glBegin(GL_LINES);
						break;
					case 3:
						glBegin(GL_TRIANGLES);
						break;
					case 4:
						glBegin(GL_QUADS);
						break;
					default:
						glBegin(GL_POLYGON);
						break;
				}
				for(tuple<int, int> vertex : vertices)
					glVertex2i(get<0>(vertex), get<1>(vertex));
				glEnd();
			}