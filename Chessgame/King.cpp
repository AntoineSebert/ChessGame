/*
	@author Antoine "Anthony" Sébert
	@creation_date 05/11/2017
	@description king class
*/

#include "king.h"

// public
	King::King(unsigned int* newColor) {
		color = newColor;
		representation = 'K';
	}
	King::~King() {}
	char King::getRepresentation() {
		return representation;
	}
// protected
// private
