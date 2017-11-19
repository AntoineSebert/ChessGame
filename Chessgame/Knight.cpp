/*
	@author Antoine "Anthony" Sébert
	@creation_date 14/11/2017
	@description knight class
*/

#include "Knight.h"

// public
	Knight::Knight(unsigned int* newColor) {
		color = newColor;
		representation = 'B';
	}
	Knight::~Knight() {}
	char Knight::getRepresentation() {
		return representation;
	}
// protected
// private
