/*
	@author Antoine "Anthony" Sébert
	@creation_date 06/11/2017
	@description board element container
*/

#pragma once

#include <iostream>
#include <memory>

#include "Piece.h"

using namespace std;

class Cell {
	// attributes
		private:
			unsigned int color;
			weak_ptr<Piece> content;

	// methods
		public:
			Cell(unsigned int newColor);
			~Cell();
			unsigned int getColor();
			void displayContent();
			void setPiece(weak_ptr<Piece> newPiece);
			void removePiece();
		private:
			template <typename T> bool is_uninitialized(weak_ptr<T> const& weak);
};