/*
	@author Antoine "Anthony" Sébert
	@creation_date 14/11/2017
	@description queen class
*/

#pragma once

#include "Piece.h"

class Queen : public Piece {
	// attributes
		private:
			unsigned int* color;
			char representation = 'Q';

	// members
		public:
			Queen(unsigned int* newColor);
			~Queen();
		// protected
		// private
};