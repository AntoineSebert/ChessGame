/*
	@author Antoine "Anthony" Sébert
	@creation_date 10/11/2017
	@description player army container
*/

#pragma once

#include <array>
#include <iostream>
#include <iterator>

#include "Piece.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"

class Army {
	// attributes
		private:
			std::vector<std::shared_ptr<Piece>> alivePieces;
			std::vector<std::shared_ptr<Piece>> deadPieces;
			unsigned int* color;

	// membres
		public:
			Army(unsigned int* newColor);
			~Army();
			std::vector<std::shared_ptr<Piece>>* getArmyContainer();
			unsigned int getArmySize();
			void displayArmy();
			std::shared_ptr<Piece> operator[](unsigned int index);
			std::vector<std::shared_ptr<Piece>>::iterator getBegin();
			std::vector<std::shared_ptr<Piece>>::iterator getEnd();
};

