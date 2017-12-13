/*
	@author Antoine "Anthony" Sébert
	@creation_date 14/11/2017
	@description rook class
*/

#pragma once

#include <iostream>

#include "Piece.h"

class Rook : public Piece {
	// attributes
		private:
			bool hasMoved = false;

	// members
		public:
			Rook(unsigned int* newColor);
			~Rook();
			char getRepresentation();
			std::vector<boardCoord> const movement() const;
};