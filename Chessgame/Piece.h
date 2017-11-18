/*
	@author Antoine "Anthony" Sébert
	@creation_date 04/11/2017
	@description abstract class for the pieces
*/

#pragma once

#include <memory>
#include <string>
#include <vector>

using namespace std;

class Piece {
	// attributes
		// public
		// protected
		private:
			char representation;
			string position;

	// members
		public:
			Piece();
			//virtual vector<Cell> const& possibleMoves() const = 0;
			virtual char getRepresentation() = 0;
		// protected
		// private
};