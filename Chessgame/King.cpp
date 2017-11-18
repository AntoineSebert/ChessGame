/*
	@author Antoine "Anthony" Sébert
	@creation_date 05/11/2017
	@description king class
*/

#include "king.h"

// public
	King::King(unsigned int newPosition, unsigned int* newColor) {
		color = newColor;
		position = newPosition;
		representation = 'B';
	}
	King::~King() {}
	char King::getRepresentation() {
		return representation;
	}
// protected
// private
