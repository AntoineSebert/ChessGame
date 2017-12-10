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

// data
	const unsigned int WINDOW_WIDTH = 1200;
	const unsigned int WINDOW_HEIGHT = 800;
	const char WINDOW_NAME[] = "1705851";

	//void* parameter;

	typedef std::array<double, 4> rgba;
	typedef std::array<double, 3> rgb;
	typedef std::tuple<int, int> coord;

	const rgba BLACK = { 0.0, 0.0, 0.0, 1.0 };
	const rgba BLEU = { 0.0, 0.0, 1.0, 1.0 };
	const rgba GREEN = { 0.0, 1.0, 0.0, 1.0 };
	const rgba CYAN = { 0.0, 1.0, 1.0, 1.0 };
	const rgba RED = { 1.0, 0.0, 0.0, 1.0 };
	const rgba MAGENTA = { 1.0, 0.0, 1.0, 1.0 };
	const rgba YELLOW = { 1.0, 1.0, 0.0, 1.0 };
	const rgba WHITE = { 1.0, 1.0, 1.0, 1.0 };

// functions
	// initialization
		void initializeViewPort();
		void initializeWindow();
		void initializeGlut(int argc, char *argv[]);
	// event
		void reshape(int width, int height);
		void difficutyMenuClick(int button, int state, int x, int y);
	// drawing
		// high level
			void drawDifficultyMenu();
			void drawBoard();
		// medium level
			void drawButton(coord origin, unsigned int width, unsigned int height, rgba color);
			void drawGrid(coord origin, int width, int height);
			void drawOrigin();
			void drawPiece(char representation, rgba color);
			void drawCase(coord origin, unsigned int width, rgba color);
			void drawText(std::string text);
		// low level
			void drawGeometric(std::list<coord>* vertices, rgba color);
			void drawCircle(float cx, float cy, float r, unsigned int num_segments);