/**
	\author Antoine "Anthony" Sébert
	\date 14/11/2017
	\brief bishop class
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