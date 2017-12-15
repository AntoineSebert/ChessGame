/*!
	\author		Antoine "Anthony" Sébert
	\date		04/11/2017
	\brief		Abstract class for the pieces.
	\details	Pack all necessary members for pieces. Force all derived classes to implement and redefine piece-specific functions.
*/

#pragma once

#include <string>
#include <tuple>
#include <vector>

typedef std::tuple<unsigned int, unsigned int> boardCoord;

class Piece {
	// attributes
		protected:
			char representation;
			boardCoord position;
			unsigned int* color = nullptr;

	// members
		public:
			Piece();
			virtual std::vector<boardCoord> const movement() const = 0;
			virtual char getRepresentation() = 0;
			boardCoord getPosition();
			void setPosition(boardCoord newPosition);
		protected:
			std::vector<boardCoord> const& linesPositions() const;
};