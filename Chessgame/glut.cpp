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
		void difficutyMenuClick(int button, int state, int x, int y) {
			cout << x << ':' << y << endl;
		}
	// drawing
		// high level
			void drawDifficultyMenu() {
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Efface le frame buffer et le Z-buffer
				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity(); // Réinitialise la matrice
				gluLookAt(0, 0, 100, 0, 0, 0, 0, 1, 0);

				drawButton(forward_as_tuple(1, 2), 1, 4, YELLOW);
				drawGrid(forward_as_tuple(-60, -40), 120, 80);
				drawOrigin();
				drawCircle(10, 10, 2, 32);

				glutSwapBuffers();
				glutPostRedisplay();
			}
			void drawBoard() {

			}
		// medium level
			void drawButton(coord origin, unsigned int height, unsigned int width, rgba color) {
				list<coord> coords = {
					make_tuple(get<0>(origin), get<1>(origin)),
					make_tuple(get<0>(origin) + width, get<1>(origin)),
					make_tuple(get<0>(origin) + width, get<1>(origin) + height),
					make_tuple(get<0>(origin), get<1>(origin) + height)
				};
				drawGeometric(&coords, color);
				// draw text
			}
			void drawGrid(coord origin, int width, int height) {
				for (int ii = get<1>(origin); ii < get<1>(origin) + height; ++ii) {
					for (int i = get<0>(origin); i < get<0>(origin) + width; ++i)
						drawGeometric(
							&(list<coord>() = { make_tuple(i, ii) }),
							WHITE
						);
				}
			}
			void drawOrigin() {
				list<coord> coords = {
					make_tuple(-1, 0),
					make_tuple(1, 0),
				};
				drawGeometric(&coords, WHITE);
				coords = {
					make_tuple(0, -1),
					make_tuple(0, 1),
				};
				drawGeometric(&coords, WHITE);
			}
			void drawPiece(char representation, rgba color) {
				drawCircle(10, 10, 2, 32);
			}
			void drawCase(coord origin, unsigned int width, rgba color) {
				list<coord> coords = {
					make_tuple(get<0>(origin), get<1>(origin)),
					make_tuple(get<0>(origin) + width, get<1>(origin) + width),
				};
				drawGeometric(&coords, color);
			}
		// low level
			void drawGeometric(list<coord>* vertices, rgba color) {
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
					color.at(0),
					color.at(1),
					color.at(2),
					color.at(3)
				);
				for (auto vertex : *vertices)
					glVertex2i(get<0>(vertex), get<1>(vertex));
				glEnd();
			}
			void drawCircle(float cx, float cy, float r, unsigned int segments) {
				glBegin(GL_LINE_LOOP);
				for (unsigned int i = 0; i < segments; ++i) {
					float theta = 2.0f * 3.1415926f * float(i) / float(segments);

					float x = r * cosf(theta);
					float y = r * sinf(theta);

					glVertex2f(x + cx, y + cy);
				}
				glEnd();
			}