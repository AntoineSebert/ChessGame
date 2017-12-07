/*
	@author Antoine "Anthony" S�bert
	@creation_date 14/11/2017
	@description queen class
*/

#pragma once

#include "Piece.h"

class Queen : public Piece {
	// members
		public:
			Queen(unsigned int* newColor);
			~Queen();
			char getRepresentation();
			std::vector<std::tuple<unsigned int, unsigned int>> const movement() const;
};