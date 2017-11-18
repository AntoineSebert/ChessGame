/*
	@author Antoine "Anthony" Sébert
	@creation_date 14/11/2017
	@description pawn class
*/

#pragma once

#include "Piece.h"

class Pawn : public Piece {
	// members
		public:
			Pawn(unsigned int newPosition, unsigned int* newColor);
			~Pawn();
			char getRepresentation();
		// protected
		// private
};