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
				data.at(i).at(ii) = make_shared<Cell>((i + ii) % 2);
		}
	}
	void Board::display(unsigned int turns) {
		if (turns % 2 == 0) {
			for (auto array : data) {
				for (auto cell : array)
					cell->displayContent();
				cout << endl;
			}
		}
		else {
			for (auto it = data.rbegin(); it != data.rend(); ++it) {
				for (auto cell : *it)
					cell->displayContent();
				cout << endl;
			}
		}
	}
	array<array<shared_ptr<Cell>, 8>, 8>* Board::getData() { return &data; }
	array<shared_ptr<Cell>, 8> Board::operator[](unsigned int index) { return data.at(index); }
	shared_ptr<Cell> Board::operator()(unsigned int index, unsigned int index2) { return data.at(index).at(index2); }
	array<array<shared_ptr<Cell>, 8>, 8>::iterator Board::getBegin() { return data.begin(); }
	array<shared_ptr<Cell>, 8>::iterator Board::getBegin(unsigned int index) { return data.at(index).begin(); }
	array<array<shared_ptr<Cell>, 8>, 8>::iterator Board::getEnd() { return data.end(); }
	array<shared_ptr<Cell>, 8>::iterator Board::getEnd(unsigned int index) { return data.at(index).end(); }
	// protected
// private
	Board::Board() {}
	Board::~Board() {}
