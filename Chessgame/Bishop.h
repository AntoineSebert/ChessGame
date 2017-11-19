/*
	@author Antoine "Anthony" Sébert
	@creation_date 14/11/2017
	@description bishop class
*/

#pragma once

#include "Piece.h"

class Bishop : public Piece {
	// members
		public:
			Bishop(unsigned int* newColor);
			~Bishop();
			char getRepresentation();
		// protected
		// private
};