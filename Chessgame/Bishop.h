/*!
	\author	Antoine "Anthony" Sébert
	\date	14/11/2017
	\brief	Bishop class.
*/

#pragma once

#include "Piece.h"

class Bishop : public Piece {
	// members
		public:
			Bishop(unsigned int* newColor);
			~Bishop();
			char getRepresentation();
			std::vector<boardCoord> const movement() const;
};