/*
	@author Antoine "Anthony" S�bert
	@creation_date 14/11/2017
	@description pawn class
*/

#pragma once

#include "Piece.h"

class Pawn : public Piece {
	// attributes
		private:
			bool hasMoved = false;

	// members
		public:
			Pawn(unsigned int* newColor);
			~Pawn();
			char getRepresentation();
			std::vector<boardCoord> const movement() const;
};