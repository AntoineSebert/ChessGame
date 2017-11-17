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
				data.at(i).at(ii) = std::make_shared<Cell>((i + ii) % 2);
		}
	}
	void Board::display(unsigned int turns) {
		if (turns % 2 == 0) {
			for (auto array : data) {
				for (auto cell : array)
					cell->displayContent();
				std::cout << std::endl;
			}
		}
		else {
			for (auto it = data.rbegin(); it != data.rend(); ++it) {
				for (auto cell : *it)
					cell->displayContent();
				std::cout << std::endl;
			}
		}
	}
	std::array<std::array<std::shared_ptr<Cell>, 8>, 8>* Board::getData() { return &data; }
	std::array<std::shared_ptr<Cell>, 8> Board::operator[](unsigned int index) { return data.at(index); }
	std::shared_ptr<Cell> Board::operator()(unsigned int index, unsigned int index2) { return data.at(index).at(index2); }
	std::array<std::array<std::shared_ptr<Cell>, 8>, 8>::iterator Board::getBegin() { return data.begin(); }
	std::array<std::shared_ptr<Cell>, 8>::iterator Board::getBegin(unsigned int index) { return data.at(index).begin(); }
	std::array<std::array<std::shared_ptr<Cell>, 8>, 8>::iterator Board::getEnd() { return data.end(); }
	std::array<std::shared_ptr<Cell>, 8>::iterator Board::getEnd(unsigned int index) { return data.at(index).end(); }
	// protected
// private
	Board::Board() {}
	Board::~Board() {}
