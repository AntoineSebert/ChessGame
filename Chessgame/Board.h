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

using namespace std;

class Board : public Singleton<Board> {
	friend class Singleton<Board>;
	// attributes
		private:
			array<array<shared_ptr<Cell>, 8>, 8> data;

	// methods
		public:
			void initialize();
			void display(unsigned int turns);
			array<array<shared_ptr<Cell>, 8>, 8>* getData();
			array<shared_ptr<Cell>, 8> operator[](unsigned int index);
			shared_ptr<Cell> operator()(unsigned int index, unsigned int index2);
			array<array<shared_ptr<Cell>, 8>, 8>::iterator getBegin();
			array<shared_ptr<Cell>, 8>::iterator getBegin(unsigned int index);
			array<array<shared_ptr<Cell>, 8>, 8>::iterator getEnd();
			array<shared_ptr<Cell>, 8>::iterator getEnd(unsigned int index);
		private:
			Board();
			~Board();
};

