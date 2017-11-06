#pragma once

#include "Singleton.h"
#include "Game.h"
#include "Cell.h"

#include <array>
#include <memory>

/*
	@author Antoine "Anthony" Sébert
	@creation_date 06/11/2017
	@description game board container
*/

class Board : public Singleton<Board> {
	friend class Singleton<Board>;
	// attributes
		std::array<std::array<Cell, 8>, 8> data;
		std::weak_ptr<Game> parent;
		
	// methods
		public:
			void initialize();
		private:
			Board();
			~Board();
};

