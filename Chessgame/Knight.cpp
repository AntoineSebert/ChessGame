/*
	@author Antoine "Anthony" Sébert
	@creation_date 14/11/2017
	@description knight class
*/

#include "Knight.h"

// public
	Knight::Knight(unsigned int* newColor) {
		color = newColor;
		representation = 'k';
	}
	Knight::~Knight() {}
	char Knight::getRepresentation() {
		return representation;
	}
	vector<tuple<unsigned int, unsigned int>> const Knight::movement() const {
		return vector<tuple<unsigned int, unsigned int>>();
	}
// protected
// private
