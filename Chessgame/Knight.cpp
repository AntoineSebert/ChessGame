/*!
	\author Antoine "Anthony" Sébert
	\date 14/11/2017
	\brief knight class
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
