/*
	@author Antoine "Anthony" Sébert
	@creation_date 04/11/2017
	@description abstract class for the pieces
*/

#pragma once

#include <string>
#include <functional>
#include <tuple>
#include <vector>

class Piece {
	// attributes
		protected:
			char representation;
			std::tuple<unsigned int, unsigned int> position;
			unsigned int* color = nullptr;

	// members
		public:
			Piece();
			virtual std::vector<std::tuple<unsigned int, unsigned int>> const movement() const = 0;
			virtual char getRepresentation() = 0;
			std::tuple<unsigned int, unsigned int> getPosition();
			void setPosition(std::tuple<unsigned int, unsigned int> newPosition);
		protected:
			std::vector<std::tuple<unsigned int, unsigned int>> const& linesPositions() const;
};