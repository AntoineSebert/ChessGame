/*
	@author Antoine "Anthony" Sébert
	@creation_date 14/11/2017
	@description rook class
*/

#pragma once

#include "Piece.h"

class Rook : public Piece {
	// attributes
		private:
			unsigned int* color;
			char representation = 'R';

	// members
		public:
			Rook(unsigned int* newColor);
			~Rook();
			char getRepresentation();
		// protected
		// private
};