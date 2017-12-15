/**
	\author Antoine "Anthony" Sébert
	\date 06/11/2017
	\brief game board container
*/

#pragma once

#include <array>
#include <memory>
#include <iterator>

#include "Singleton.h"
#include "Cell.h"

typedef std::array<std::shared_ptr<Cell>, 8> boardRow;

class Board : public Singleton<Board> {
	friend class Singleton<Board>;
	// attributes
		private:
			std::array<boardRow, 8> data;

	// methods
		public:
			void initialize();
			void display(unsigned int turns);
			std::array<boardRow, 8>* getData();
			boardRow operator[](unsigned int index);
			std::shared_ptr<Cell> operator()(unsigned int index, unsigned int index2);
			std::array<boardRow, 8>::iterator getBegin();
			boardRow::iterator getBegin(unsigned int index);
			std::array<boardRow, 8>::iterator getEnd();
			boardRow::iterator getEnd(unsigned int index);
		private:
			Board();
			~Board();
};

