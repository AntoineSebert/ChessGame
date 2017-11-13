/*
	@author Antoine "Anthony" Sébert
	@creation_date 10/11/2017
	@description player army container
*/

#pragma once

#include <array>

#include "Piece.h"

class Army {
	// attributes
		private:
			std::array<Piece*, 16> alivePieces;

	// membres
		public:
			Army();
			~Army();
};

