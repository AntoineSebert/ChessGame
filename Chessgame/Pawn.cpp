/*
	@author Antoine "Anthony" Sébert
	@creation_date 14/11/2017
	@description pawn class
*/

#include "Pawn.h"

// public
	Pawn::Pawn(unsigned int* newColor) {
		color = newColor;
		representation = 'B';
	}
	Pawn::~Pawn() {}
	char Pawn::getRepresentation() {
		return representation;
	}
// protected
// private
