/*
	@author Antoine "Anthony" S�bert
	@creation_date 06/11/2017
	@description board element container
*/

#pragma once

#include <iostream>
#include <memory>

#include "Piece.h"

class Cell {
	// attributes
		private:
			unsigned int color;
			std::weak_ptr<Piece> content;

	// methods
		public:
			Cell(unsigned int newColor);
			~Cell();
			unsigned int getColor();
			void displayContent();
			void setPiece(Piece* newPiece);
			void removePiece();
};

