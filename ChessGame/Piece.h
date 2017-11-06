#pragma once

#include "Player.h"
#include "Cell.h"

#include <vector>
#include <memory>

/*
	@author Antoine "Anthony" Sébert
	@creation_date 04/11/2017
	@description abstract class for the pieces
*/

class Piece {
	// attributes
		// public
		// protected
		private:
			std::weak_ptr<Player> owner;
			char representation;

	// members
		public:
			Piece(std::weak_ptr<Player> newOwner);
			virtual std::vector<Cell> const& possibleMoves() const = 0;
			char getRepresentation();
		// protected
		// private
};