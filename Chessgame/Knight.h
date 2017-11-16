/*
	@author Antoine "Anthony" Sébert
	@creation_date 14/11/2017
	@description knight class
*/

#pragma once

#include "Piece.h"

class Knight : public Piece {
	// attributes
		private:
			unsigned int* color;
			char representation = 'k';

	// members
		public:
			Knight(unsigned int* newColor);
			~Knight();
			char getRepresentation();
		// protected
		// private
};