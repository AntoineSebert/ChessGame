/*
	@author Antoine "Anthony" Sébert
	@creation_date 07/12/2017
	@description glut related functions
*/

#include "glut.h"

using namespace std;

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
			glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
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
			);
			glMatrixMode(GL_MODELVIEW);
		}
		void difficutyMenuClick(int button, int state, int x, int y) {}
	// drawing
		// high level
			void drawDifficultyMenu() {
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Efface le frame buffer et le Z-buffer
				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity(); // Réinitialise la matrice
				gluLookAt(0, 0, -10, 0, 0, 0, 0, 1, 0);

				drawButton(0, 0, 1, 4, &(array<double, 4>() = { 1.0, 0.8, 0.0, 0.8 }));
				drawButton(1, 2, 1, 4, &(array<double, 4>() = { 1.0, 0.8, 0.0, 0.8 }));
				drawGrid(-5, 5);
				drawOrigin();

				glutSwapBuffers();
				glutPostRedisplay();
			}
		// medium level
			void drawButton(int posx, int posy, int height, int width, array<double, 4>* color) {
				list<tuple<int, int>> coords = {
					make_tuple(posx, posy),
					make_tuple(posx + width, posy),
					make_tuple(posx + width, posy + height),
					make_tuple(posx, posy + height)
				};
				drawGeometric(&coords, color);
			}
			void drawGrid(int start, int end) {
				if (start < end) {
					for (int i = start; i < end; ++i) {
						for (int ii = start; ii < end; ++ii)
							drawGeometric(
								&(list<tuple<int, int>>() = { make_tuple(i, ii) }),
								&(array<double, 4>() = { 1.0, 1.0, 1.0, 1.0 })
							);
					}
				}
			}
			void drawOrigin() {
				list<tuple<int, int>> coords = {
					make_tuple(-1, 0),
					make_tuple(1, 0),
				};
				drawGeometric(&coords, &(array<double, 4>() = { 1.0, 1.0, 1.0, 1.0 }));
				coords = {
					make_tuple(0, -1),
					make_tuple(0, 1),
				};
				drawGeometric(&coords, &(array<double, 4>() = { 1.0, 1.0, 1.0, 1.0 }));
			}
		// low level
			void drawGeometric(list<tuple<int, int>>* vertices, array<double, 4>* color) {
				switch (vertices->size()) {
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
				glColor4d(
					color->at(0),
					color->at(1),
					color->at(2),
					color->at(3)
				);
				for (auto vertex : *vertices)
					glVertex2i(get<0>(vertex), get<1>(vertex));
				glEnd();
			}