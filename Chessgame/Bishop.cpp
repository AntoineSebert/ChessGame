/*
	@author Antoine "Anthony" S�bert
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
// protected
// private
