/**
	\author Antoine "Anthony" Sébert
	\date 06/11/2017
	\brief game board container
*/

#include "Board.h"

using namespace std;

// public
	void Board::initialize() {
		for (size_t i = 0; i < data.size(); ++i) {
			for (size_t ii = 0; ii < data.size(); ++ii)
				data.at(i).at(ii) = make_shared<Cell>((i + ii) % 2);
		}
	}
	void Board::display(unsigned int turns) {
		for (unsigned int i = 0; i < data.size() + 1; ++i)
			cout << (i == 0 ? ' ' : (char)(i + 64));
		cout << endl;
		auto begin = (turns % 2 == 0 ? 0 : data.size() - 1);
		auto end = (turns % 2 == 0 ? data.size() : -1);
		for (; begin != end; (turns % 2 == 0 ? ++begin : --begin)) {
			cout << begin;
			for (shared_ptr<Cell> cell : data.at(begin))
				cell->displayContent();
			cout << endl;
		}
	}
	array<boardRow, 8>* Board::getData() { return &data; }
	boardRow Board::operator[](unsigned int index) { return data.at(index); }
	shared_ptr<Cell> Board::operator()(unsigned int index, unsigned int index2) { return data.at(index).at(index2); }
	array<boardRow, 8>::iterator Board::getBegin() { return data.begin(); }
	boardRow::iterator Board::getBegin(unsigned int index) { return data.at(index).begin(); }
	array<boardRow, 8>::iterator Board::getEnd() { return data.end(); }
	boardRow::iterator Board::getEnd(unsigned int index) { return data.at(index).end(); }
// protected
// private
	Board::Board() {}
	Board::~Board() {}