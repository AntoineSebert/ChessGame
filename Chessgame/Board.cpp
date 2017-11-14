/*
	@author Antoine "Anthony" Sébert
	@creation_date 06/11/2017
	@description game board container
*/

#include "Board.h"

// public
	void Board::initialize() {
		for (size_t i = 0; i < data.size(); ++i) {
			for (size_t ii = 0; ii < data.size(); ++ii)
				data[i][ii] = new Cell((i + ii) % 2);
		}
	}
	void Board::display(unsigned int turns) {
		if (turns % 2 == 0) {
			for (std::array<Cell*, 8> array : data) {
				for (Cell* cell : array)
					cell->displayContent();
				std::cout << std::endl;
			}
		}
		else {
			for (auto it = data.rbegin(); it != data.rend(); ++it) {
				for (Cell* cell : *it)
					cell->displayContent();
				std::cout << std::endl;
			}
		}
	}
// protected
// private
	Board::Board() {}
	Board::~Board() {
		for (size_t i = 0; i < data.size(); ++i) {
			for (size_t ii = 0; ii < data.size(); ++ii)
				delete(data[i][ii]);
		}
	}
