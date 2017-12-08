/*
	@author Antoine "Anthony" Sébert
	@creation_date 04/12/2017
	@description glut related functions & data header
*/

#pragma once

#include <array>
#include <list>
#include <tuple>
#include <GL\glew.h>
#include <GL\freeglut.h>

// data
	const unsigned int WINDOW_WIDTH = 1200;
	const unsigned int WINDOW_HEIGHT = 800;
	const char WINDOW_NAME[] = "1705851";

	//void* parameter;

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
		// medium level
			void drawButton(int posx, int posy, int height, int width, std::array<double, 4>* color);
			void drawGrid(int start, int end);
			void drawOrigin();
		// low level
			void drawGeometric(std::list<std::tuple<int, int>>* vertices, std::array<double, 4>* color);