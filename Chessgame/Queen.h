/*!
	\author	Antoine "Anthony" Sébert
	\date	14/11/2017
	\brief	Queen class.
*/

#pragma once

#include "Piece.h"

class Queen : public Piece {
	// members
		public:
			Queen(unsigned int* newColor);
			~Queen();
			char getRepresentation();
			std::vector<boardCoord> const movement() const;
};