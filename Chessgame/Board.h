/*
	@author Antoine "Anthony" Sébert
	@creation_date 06/11/2017
	@description game board container
*/

#pragma once

#include <array>
#include <memory>
#include <iterator>

#include "Singleton.h"
#include "Cell.h"

class Board : public Singleton<Board> {
	friend class Singleton<Board>;
	// attributes
		private:
			std::array<std::array<std::shared_ptr<Cell>, 8>, 8> data;

	// methods
		public:
			void initialize();
			void display(unsigned int turns);
			std::array<std::array<std::shared_ptr<Cell>, 8>, 8>* getData();
			std::array<std::shared_ptr<Cell>, 8> operator[](unsigned int index);
			std::shared_ptr<Cell> operator()(unsigned int index, unsigned int index2);
			std::array<std::array<std::shared_ptr<Cell>, 8>, 8>::iterator getBegin();
			std::array<std::shared_ptr<Cell>, 8>::iterator getBegin(unsigned int index);
			std::array<std::array<std::shared_ptr<Cell>, 8>, 8>::iterator getEnd();
			std::array<std::shared_ptr<Cell>, 8>::iterator getEnd(unsigned int index);
		private:
			Board();
			~Board();
};

