/*
	@author Antoine "Anthony" Sébert
	@creation_date 14/11/2017
	@description pawn class
*/

#pragma once

#include "Piece.h"

class Pawn : public Piece {
	// attributes
		private:
			unsigned int* color;
			char representation = 'p';

	// members
		public:
			Pawn(unsigned int* newColor);
			~Pawn();
		// protected
		// private
};