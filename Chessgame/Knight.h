/*
	@author Antoine "Anthony" Sébert
	@creation_date 14/11/2017
	@description knight class
*/

#pragma once

#include "Piece.h"

class Knight : public Piece {
	// members
		public:
			Knight(unsigned int* newColor);
			~Knight();
			char getRepresentation();
			std::vector<std::tuple<unsigned int, unsigned int>> const movement() const;
};