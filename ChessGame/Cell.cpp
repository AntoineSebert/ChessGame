#include "Cell.h"

/*
	@author Antoine "Anthony" Sébert
	@creation_date 06/11/2017
	@description board element container
*/

Cell::Cell(unsigned int newColor) : color(newColor) {}

Cell::~Cell() {}

unsigned int Cell::getColor() {
	return color;
}