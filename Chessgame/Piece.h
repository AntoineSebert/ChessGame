/*
	@author Antoine "Anthony" Sébert
	@creation_date 04/11/2017
	@description abstract class for the pieces
*/

#pragma once

#include <memory>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

class Piece {
	// attributes
		protected:
			char representation;
			tuple<unsigned int, unsigned int> position;
			unsigned int* color;

	// members
		public:
			Piece();
			//virtual vector<Cell> const& possibleMoves() const = 0;
			virtual char getRepresentation() = 0;
			tuple<unsigned int, unsigned int> getPosition();
			void setPosition(tuple<unsigned int, unsigned int> newPosition);
};