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

using namespace std;

class Army {
	// attributes
		private:
			vector<shared_ptr<Piece>> alivePieces;
			vector<shared_ptr<Piece>> deadPieces;
			unsigned int* color;

	// membres
		public:
			Army(unsigned int* newColor);
			~Army();
			vector<shared_ptr<Piece>>* getArmyContainer();
			unsigned int getArmySize();
			void displayArmy();
			shared_ptr<Piece> operator[](unsigned int index);
			vector<shared_ptr<Piece>>::iterator getBegin();
			vector<shared_ptr<Piece>>::iterator getEnd();
};

