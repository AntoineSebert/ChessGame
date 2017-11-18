/*
	@author Antoine "Anthony" S�bert
	@creation_date 14/11/2017
	@description rook class
*/

#pragma once

#include "Piece.h"

class Rook : public Piece {
	// members
		public:
			Rook(unsigned int newPosition, unsigned int* newColor);
			~Rook();
			char getRepresentation();
		// protected
		// private
};