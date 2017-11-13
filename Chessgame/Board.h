/*
	@author Antoine "Anthony" S�bert
	@creation_date 06/11/2017
	@description game board container
*/

#pragma once

#include <array>
#include <memory>

#include "Singleton.h"
//#include "Cell.h"

class Board : public Singleton<Board> {
	friend class Singleton<Board>;
	// attributes
		// public
		// protected
		private:
			//std::array<std::array<Cell, 8>, 8> data;

	// methods
		public:
			void initialize();
		private:
			Board();
			~Board();
};

