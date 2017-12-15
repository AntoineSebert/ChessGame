/**
	\author Antoine "Anthony" Sébert
	\date 05/11/2017
	\brief king class
*/

#include "king.h"

using namespace std;

// public
	King::King(unsigned int* newColor) {
		color = newColor;
		representation = 'K';
	}
	King::~King() {}
	char King::getRepresentation() {
		return representation;
	}
	vector<boardCoord> const King::movement() const {
		return vector<boardCoord>();
	}
// protected
// private
