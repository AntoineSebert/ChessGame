/*
	@author Antoine "Anthony" Sébert
	@creation_date 14/11/2017
	@description rook class
*/

#include "Rook.h"

// public
	Rook::Rook(unsigned int* newColor) {
		color = newColor;
		representation = 'R';
	}
	Rook::~Rook() {}
	char Rook::getRepresentation() {
		return representation;
	}
	vector<tuple<unsigned int, unsigned int>> const Rook::movement() const {
		return const_cast<vector<tuple<unsigned int, unsigned int>>&>(linesPositions());
	}