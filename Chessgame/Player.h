/*
	@author Antoine "Anthony" Sébert
	@creation_date 06/11/2017
	@description player
*/

#pragma once

#include <memory>
#include <iostream>
#include <iterator>
#include <string>

#include "Army.h"
#include "Board.h"

using namespace std;

class Player {
	// attributes
		private:
			unique_ptr<Army> playerArmy;
			unsigned int color;
			string name;

	// members
		public:
			Player(string playerName, unsigned int newColor);
			~Player();
			string getName();
			unsigned int getColor();
			void initializeArmy(Board* gameBoard);
		// protected
		private:
			void placePieces(
				array<shared_ptr<Cell>, 8>::iterator cellStart, array<shared_ptr<Cell>, 8>::iterator cellEnd,
				vector<shared_ptr<Piece>>::iterator pieceStart, vector<shared_ptr<Piece>>::iterator pieceEnd
			);
};