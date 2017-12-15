/**
	@author Antoine "Anthony" Sébert
	@creation_date 14/11/2017
	@description knight class
*/

#include "Knight.h"

using namespace std;

// public
	Knight::Knight(unsigned int* newColor) {
		color = newColor;
		representation = 'k';
	}
	Knight::~Knight() {}
	char Knight::getRepresentation() {
		return representation;
	}
	vector<boardCoord> const Knight::movement() const {
		return vector<boardCoord>();
	}
// protected
// private
