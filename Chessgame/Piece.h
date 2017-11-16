/*
	@author Antoine "Anthony" Sébert
	@creation_date 04/11/2017
	@description abstract class for the pieces
*/

#pragma once

#include <vector>
#include <memory>

class Piece {
	// attributes
		// public
		// protected
		private:
			char representation;

	// members
		public:
			Piece();
			//virtual std::vector<Cell> const& possibleMoves() const = 0;
			virtual char getRepresentation() = 0;
		// protected
		// private
};