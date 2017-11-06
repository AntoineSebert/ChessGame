#pragma once

#include "Piece.h"

#include <memory>

/*
	@author Antoine "Anthony" Sébert
	@creation_date 06/11/2017
	@description board element container
*/

class Cell {
	// attributes
		private:
			unsigned int color;
			std::weak_ptr<Piece> content;

	// methods
		public:
			Cell();
			~Cell();
};

