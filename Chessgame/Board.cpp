/*
	@author Antoine "Anthony" S�bert
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
	std::array<std::array<Cell*, 8>, 8>* Board::getData() {
		return &data;
	}
	std::array<std::array<Cell*, 8>, 8>::iterator Board::getBegin() {
		return data.begin();
	}
	std::array<Cell*, 8>::iterator Board::getBegin(unsigned int index) {
		return data.at(index).begin();
	}
	std::array<std::array<Cell*, 8>, 8>::iterator Board::getEnd() {
		return data.end();
	}
	std::array<Cell*, 8>::iterator Board::getEnd(unsigned int index) {
		return data.at(index).end();
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
