/*
	@author Antoine "Anthony" Sébert
	@creation_date 06/11/2017
	@description game board container
*/

#pragma once

#include <array>
#include <memory>

#include "Singleton.h"
#include "Cell.h"

class Board : public Singleton<Board> {
	friend class Singleton<Board>;
	// attributes
		private:
			std::array<std::array<Cell*, 8>, 8> data;

	// methods
		public:
			void initialize();
			void display();
		private:
			Board();
			~Board();
};

