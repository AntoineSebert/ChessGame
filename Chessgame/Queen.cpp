/*
	@author Antoine "Anthony" Sébert
	@creation_date 14/11/2017
	@description queen class
*/

#include "Queen.h"

// public
	Queen::Queen(unsigned int* newColor) {
		color = newColor;
		representation = 'B';
	}
	Queen::~Queen() {}
	char Queen::getRepresentation() {
		return representation;
	}
// protected
// private
