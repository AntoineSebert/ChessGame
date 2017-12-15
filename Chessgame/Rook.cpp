/**
	@author Antoine "Anthony" Sébert
	@creation_date 14/11/2017
	@description rook class
*/

#include "Rook.h"

using namespace std;

// public
	Rook::Rook(unsigned int* newColor) {
		color = newColor;
		representation = 'R';
	}
	Rook::~Rook() {}
	char Rook::getRepresentation() {
		return representation;
	}
	vector<boardCoord> const Rook::movement() const {
		return const_cast<vector<boardCoord>&>(linesPositions());
	}