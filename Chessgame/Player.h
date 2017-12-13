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
#include <tuple>

#include "Army.h"
#include "Board.h"
#include "Interface.h"
#include "Piece.h"

class Player {
	// attributes
		private:
			std::unique_ptr<Army> playerArmy;
			unsigned int color;
			std::string name;
			Interface* gameInterface = nullptr;
			std::weak_ptr<Piece> selectedPiece;

	// members
		public:
			Player(std::string playerName, unsigned int newColor, Interface* newGameInterface);
			~Player();
			std::string getName();
			unsigned int getColor();
			void initializeArmy(Board* gameBoard);
			std::tuple<boardCoord, boardCoord> play(Board* gameBoard);
			void selectPiece(unsigned int number);
			void movePiece(unsigned int number);
		// protected
		private:
			void placePieces(
				unsigned int rowNumber,
				std::array<std::shared_ptr<Cell>, 8>::iterator cellStart, std::array<std::shared_ptr<Cell>, 8>::iterator cellEnd,
				std::vector<std::shared_ptr<Piece>>::iterator pieceStart, std::vector<std::shared_ptr<Piece>>::iterator pieceEnd
			);
			std::vector<unsigned int> possibleMoves(std::weak_ptr<Piece> piece);
};