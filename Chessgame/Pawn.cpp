/*
	@author Antoine "Anthony" Sébert
	@creation_date 14/11/2017
	@description pawn class
*/

#include "Pawn.h"

// public
	Pawn::Pawn(unsigned int* newColor) {
		color = newColor;
		representation = 'p';
	}
	Pawn::~Pawn() {}
	char Pawn::getRepresentation() {
		return representation;
	}
	vector<tuple<unsigned int, unsigned int>> const Pawn::movement() const {
		return vector<tuple<unsigned int, unsigned int>>();
	}
// protected
// private
