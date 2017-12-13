/*
	@author Antoine "Anthony" Sébert
	@creation_date 14/11/2017
	@description bishop class
*/

#include "Bishop.h"

using namespace std;

// public
	Bishop::Bishop(unsigned int* newColor) {
		color = newColor;
		representation = 'B';
	}
	Bishop::~Bishop() {}
	char Bishop::getRepresentation() {
		return representation;
	}
	vector<boardCoord> const Bishop::movement() const {
		return vector<boardCoord>();
	}
// protected
// private
