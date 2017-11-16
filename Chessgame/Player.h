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

class Player {
	// attributes
		private:
			std::unique_ptr<Army> playerArmy;
			unsigned int color;
			std::string name;

	// members
		public:
			Player(std::string playerName, unsigned int newColor);
			~Player();
			std::string getName();
			unsigned int getColor();
			void initializeArmy(Board* gameBoard);
		// protected
		private:
			void placePieces(
				std::array<Cell*, 8>::iterator cellStart,
				std::array<Cell*, 8>::iterator cellEnd,
				std::vector<std::shared_ptr<Piece>>::iterator pieceStart,
				std::vector<std::shared_ptr<Piece>>::iterator pieceEnd
			);
			void placePieces(
				std::array<Cell*, 8>::reverse_iterator cellStart,
				std::array<Cell*, 8>::reverse_iterator cellEnd,
				std::vector<std::shared_ptr<Piece>>::iterator pieceStart,
				std::vector<std::shared_ptr<Piece>>::iterator pieceEnd
			);
};