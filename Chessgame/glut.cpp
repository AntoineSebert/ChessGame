/**
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
			// center window
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
			// adapt content to new size
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
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
				//game.displayBoard();
				cout << x << ':' << y << endl;
				glutDisplayFunc(drawBoard);
				glutMouseFunc(boardClick);
			}
		}
		void boardClick(int button, int state, int x, int y) {
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
				cout << x << '=' << y << endl;
			}
		}
	// drawing
		// high level
			void drawDifficultyMenu() {
				// preparation
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity(); // Réinitialise la matrice
				gluLookAt(0, 0, 100, 0, 0, 0, 0, 1, 0);

				// buttons
				drawButton(forward_as_tuple(-20, 20), 40, 10, CYAN, "PVP", BLACK);
				drawButton(forward_as_tuple(-20, -5), 40, 10, YELLOW, "PVE", BLACK);
				drawButton(forward_as_tuple(-20, -30), 40, 10, GREEN, "EVE", BLACK);

				// grid and origin
				drawGrid(forward_as_tuple(-60, -40), 120, 80);
				drawOrigin();

				// refresh
				glutSwapBuffers();
				glutPostRedisplay();
			}
			void drawBoard() {
				// preparation
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity(); // Réinitialise la matrice
				gluLookAt(0, 0, 100, 0, 0, 0, 0, 1, 0);
				// draw board
				unsigned int caseWidth = 8;
				for (unsigned int ii = 0; ii < 8; ++ii) {
					for (unsigned int i = 0; i < 8; ++i) {
						drawCase(forward_as_tuple((i * caseWidth) - 32, (ii * caseWidth) - 32), caseWidth, ((i + ii) % 2 == 0 ? WHITE : BLACK));
						drawStrokedCircle(
							forward_as_tuple((i * caseWidth) - 28, (ii * caseWidth) - 28),
							(float)(caseWidth / 2) - 1,
							16,
							BLACK
						);
					}
				}
				// grid and origin
				drawGrid(forward_as_tuple(-60, -40), 120, 80);
				drawOrigin();
				// refresh
				glutSwapBuffers();
				glutPostRedisplay();
			}
		// medium level
			void drawButton(coord origin, unsigned int width, unsigned int height, rgba frameColor, string text, rgba textColor) {
				// rectangle vertices
				list<coord> coords = {
					make_tuple(get<0>(origin), get<1>(origin)),
					make_tuple(get<0>(origin) + width, get<1>(origin)),
					make_tuple(get<0>(origin) + width, get<1>(origin) + height),
					make_tuple(get<0>(origin), get<1>(origin) + height)
				};
				drawGeometric(&coords, frameColor);
				drawText(origin, text, textColor);
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
				// first segment
				list<coord> coords = {
					make_tuple(-1, 0),
					make_tuple(1, 0),
				};
				drawGeometric(&coords, BLACK);
				// second segment
				coords = {
					make_tuple(0, -1),
					make_tuple(0, 1),
				};
				drawGeometric(&coords, BLACK);
			}
			void drawPiece(char representation, rgba color) {
				drawStrokedCircle(forward_as_tuple(10, 10), 2, 32, BLACK);
				drawText(forward_as_tuple(10, 10), string(&representation), RED);
			}
			void drawCase(coord origin, unsigned int width, rgba color) {
				// fill cell
				list<coord> coords = {
					make_tuple(get<0>(origin), get<1>(origin)),
					make_tuple(get<0>(origin) + width, get<1>(origin)),
					make_tuple(get<0>(origin) + width, get<1>(origin) + width),
					make_tuple(get<0>(origin), get<1>(origin) + width)
				};
				drawGeometric(&coords, color);

				// stroke cell
				coords = {
					make_tuple(get<0>(origin), get<1>(origin)),
					make_tuple(get<0>(origin) + width, get<1>(origin))
				};
				drawGeometric(&coords, BLACK);
				coords = {
					make_tuple(get<0>(origin) + width, get<1>(origin)),
					make_tuple(get<0>(origin) + width, get<1>(origin) + width),
				};
				drawGeometric(&coords, BLACK);
				coords = {
					make_tuple(get<0>(origin) + width, get<1>(origin) + width),
					make_tuple(get<0>(origin), get<1>(origin) + width)
				};
				drawGeometric(&coords, BLACK);
				coords = {
					make_tuple(get<0>(origin), get<1>(origin)),
					make_tuple(get<0>(origin), get<1>(origin) + width)
				};
				drawGeometric(&coords, BLACK);
			}
		// low level
			void drawText(coord origin, string text, rgba color) {
				setColor(color);
				// determine text position
				glRasterPos2f((GLfloat)get<0>(origin) + 18, (GLfloat)get<1>(origin) + 5);
				// render each character
				for (char c : text)
					glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
				
			}
			void drawGeometric(list<coord>* vertices, rgba color) {
				// determine figure to draw
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
				setColor(color);
				// add vertices
				for (auto vertex : *vertices)
					glVertex2i(get<0>(vertex), get<1>(vertex));
				glEnd();
			}
			void drawStrokedCircle(coord origin, float r, unsigned int segments, rgba color) {
				drawFullCircle(origin, r, segments, color);
				drawCircleStroke(origin, r, segments, YELLOW);
			}
			void drawCircleStroke(coord origin, float r, unsigned int segments, rgba color) {
				glBegin(GL_LINE_LOOP);
				setColor(color);
				for (unsigned int i = 0; i < segments; ++i) {
					// determine angle
					float theta = 2.0f * 3.1415926f * float(i) / float(segments);
					// determine coordinates of vertex and add it
					glVertex3f((r * cosf(theta)) + get<0>(origin), (r * sinf(theta)) + get<1>(origin), 0.0);
				}
				glEnd();
			}
			void drawFullCircle(coord origin, float r, unsigned int segments, rgba color) {
				glBegin(GL_POLYGON);
				setColor(color);
				// determine coordinates of vertices and add them
				for (double i = 0; i < 2 * PI; i += PI / segments)
					glVertex3f((GLfloat)(get<0>(origin) + (cosf(i) * r)), (GLfloat)(get<1>(origin) + (sinf(i) * r)), 0.0);
				glEnd();
			}
			void setColor(rgba color) {
				glColor4d(
					color.at(0),
					color.at(1),
					color.at(2),
					color.at(3)
				);
			}
