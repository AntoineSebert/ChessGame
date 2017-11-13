/*
	@author Antoine "Anthony" S�bert
	@creation_date 06/11/2017
	@description board element container
*/

#include "Cell.h"

// public
	Cell::Cell(unsigned int newColor) : color(newColor) {}
	Cell::~Cell() {}
	unsigned int Cell::getColor() {
		return color;
	}
	void Cell::displayContent() {
		//
		// condition piece pr�sente
		//
		std::cout << "*";
	}
// protected
// private