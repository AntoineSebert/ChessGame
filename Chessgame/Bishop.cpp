/*
	@author Antoine "Anthony" Sébert
	@creation_date 14/11/2017
	@description bishop class
*/

#include "Bishop.h"

// public
	Bishop::Bishop(unsigned int* newColor) {
		color = newColor;
		representation = 'B';
	}
	Bishop::~Bishop() {}
	char Bishop::getRepresentation() {
		return representation;
	}
	vector<tuple<unsigned int, unsigned int>> const Bishop::movement() const {
		return vector<tuple<unsigned int, unsigned int>>();
	}
// protected
// private
