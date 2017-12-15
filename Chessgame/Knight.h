/*!
	\author	Antoine "Anthony" Sébert
	\date	14/11/2017
	\brief	Knight class.
*/

#pragma once

#include "Piece.h"

class Knight : public Piece {
	// members
		public:
			Knight(unsigned int* newColor);
			~Knight();
			char getRepresentation();
			std::vector<boardCoord> const movement() const;
};