/*
	@author Antoine "Anthony" S�bert
	@creation_date 14/11/2017
	@description bishop class
*/

#pragma once

#include "Piece.h"

class Bishop : public Piece {
	// attributes
		private:
			unsigned int* color;
			char representation = 'B';

	// members
		public:
			Bishop(unsigned int* newColor);
			~Bishop();
		// protected
		// private
};