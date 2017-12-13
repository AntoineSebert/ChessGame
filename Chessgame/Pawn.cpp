/*
	@author Antoine "Anthony" Sébert
	@creation_date 14/11/2017
	@description pawn class
*/

#include "Pawn.h"

using namespace std;

// public
	Pawn::Pawn(unsigned int* newColor) {
		color = newColor;
		representation = 'p';
	}
	Pawn::~Pawn() {}
	char Pawn::getRepresentation() {
		return representation;
	}
	vector<boardCoord> const Pawn::movement() const {
		return vector<boardCoord>();
	}
