/*
	@author Antoine "Anthony" S�bert
	@creation_date 14/11/2017
	@description queen class
*/

#include "Queen.h"

// public
	Queen::Queen(unsigned int newPosition, unsigned int* newColor) {
		color = newColor;
		position = newPosition;
		representation = 'B';
	}
	Queen::~Queen() {}
	char Queen::getRepresentation() {
		return representation;
	}
// protected
// private
