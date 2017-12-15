/*
	@author Antoine "Anthony" Sébert
	@creation_date 04/12/2017
	@description glut related functions & data header
*/

#pragma once

#include <array>
#include <iostream>
#include <list>
#include <string>
#include <tuple>
#include <GL\glew.h>
#include <GL\freeglut.h>

#include "Board.h"
#include "palettes.h"

// data
	const unsigned int WINDOW_WIDTH = 1200;
	const unsigned int WINDOW_HEIGHT = 800;
	const char WINDOW_NAME[] = "1705851";
	const long double PI = 3.1415926535897932384626433832795;

	typedef std::tuple<int, int> coord;
	
// functions
	// initialization
		void initializeViewPort();
		void initializeWindow();
		void initializeGlut(int argc, char *argv[]);
	// event
		void reshape(int width, int height);
		void difficutyMenuClick(int button, int state, int x, int y);
		void boardClick(int button, int state, int x, int y);
	// drawing
		// high level
			void drawDifficultyMenu();
			void drawBoard();
		// medium level
			void drawButton(coord origin, unsigned int width, unsigned int height, rgba frameColor, std::string text, rgba textColor);
			void drawGrid(coord origin, int width, int height);
			void drawOrigin();
			void drawPiece(char representation, rgba color);
			void drawCase(coord origin, unsigned int width, rgba color);
		// low level
			void drawText(coord origin, std::string text, rgba color);
			void drawGeometric(std::list<coord>* vertices, rgba color);
			void drawStrokedCircle(coord origin, float r, unsigned int segments, rgba color);
			void drawCircleStroke(coord origin, float r, unsigned int segments, rgba color);
			void drawFullCircle(coord origin, float r, unsigned int segments, rgba color);
			void setColor(rgba color);