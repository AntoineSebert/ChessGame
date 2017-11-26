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
#include "Interface.h"
#include "Piece.h"

using namespace std;

class Player {
	// attributes
		private:
			unique_ptr<Army> playerArmy;
			unsigned int color;
			string name;
			Interface* gameInterface = nullptr;
			weak_ptr<Piece> selectedPiece;

	// members
		public:
			Player(string playerName, unsigned int newColor, Interface* newGameInterface);
			~Player();
			string getName();
			unsigned int getColor();
			void initializeArmy(Board* gameBoard);
			void play(Board* gameBoard);
			void selectPiece(unsigned int number);
			void movePiece(unsigned int number);
		// protected
		private:
			void placePieces(
				unsigned int rowNumber,
				array<shared_ptr<Cell>, 8>::iterator cellStart, array<shared_ptr<Cell>, 8>::iterator cellEnd,
				vector<shared_ptr<Piece>>::iterator pieceStart, vector<shared_ptr<Piece>>::iterator pieceEnd
			);
			vector<unsigned int> possibleMoves(weak_ptr<Piece> piece);
};