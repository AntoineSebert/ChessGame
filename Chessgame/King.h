/**
	@author Antoine "Anthony" Sébert
	@creation_date 05/11/2017
	@description king class
*/

#pragma once

#include "Piece.h"

class King : public Piece {
	// attributes
		private:
			bool hasMoved = false;
			bool hasBeenPutInCheck = false;

	// members
		public:
			King(unsigned int* newColor);
			~King();
			char getRepresentation();
			std::vector<boardCoord> const movement() const;
};

