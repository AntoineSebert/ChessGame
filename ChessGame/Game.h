#pragma once

#include "Singleton.h"

#include <array>

/*
	@author Antoine "Anthony" Sébert
	@creation_date 05/11/2017
	@description game initializer and handler
*/

class Game : public Singleton<Game> {
	friend class Singleton<Game>;
	// attributes
		// public
		// protected
		private:
			Board* gameBoard;
			std::array<Player, 2> players;

	// members
		public:
			void initialize();
		// protected
		private:
};

