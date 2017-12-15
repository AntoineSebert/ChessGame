/*!
	\author Antoine "Anthony" Sébert
	\date 14/11/2017
	\brief pawn class
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
