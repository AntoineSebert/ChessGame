/*
	@author Antoine "Anthony" Sébert
	@creation_date 10/11/2017
	@description player army container
*/

#include "Army.h"

// public
	Army::Army(unsigned int* newColor) : color(newColor) {
		for (unsigned int i = 8; i < alivePieces.size(); ++i)
			alivePieces.at(i) = new Rook(color);
	}
	Army::~Army() {
		for (unsigned int i = 0; i < alivePieces.size(); ++i)
			delete(alivePieces.at(i));
	}
// protected
// private