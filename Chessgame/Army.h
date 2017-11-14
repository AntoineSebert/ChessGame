/*
	@author Antoine "Anthony" Sébert
	@creation_date 10/11/2017
	@description player army container
*/

#pragma once

#include <array>
#include <iostream>

#include "Piece.h"
#include "Rook.h"

class Army {
	// attributes
		private:
			std::array<Piece*, 16> alivePieces;
			std::array<Piece*, 15> deadPieces;
			unsigned int* color;

	// membres
		public:
			Army(unsigned int* newColor);
			~Army();
};

