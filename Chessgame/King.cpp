/*
	@author Antoine "Anthony" Sébert
	@creation_date 05/11/2017
	@description king class
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
	vector<tuple<unsigned int, unsigned int>> const King::movement() const {
		return vector<tuple<unsigned int, unsigned int>>();
	}
// protected
// private
