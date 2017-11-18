/*
	@author Antoine "Anthony" S�bert
	@creation_date 14/11/2017
	@description pawn class
*/

#include "Pawn.h"

// public
	Pawn::Pawn(unsigned int newPosition, unsigned int* newColor) {
		color = newColor;
		position = newPosition;
		representation = 'B';
	}
	Pawn::~Pawn() {}
	char Pawn::getRepresentation() {
		return representation;
	}
// protected
// private
