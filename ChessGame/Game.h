#pragma once

#include "Singleton.h"

#include "difficulties.h"
#include "gameModes.h"

#include "Board.h"
#include "Player.h"
#include "Interface.h"

#include <array>
#include <memory>

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
			std::unique_ptr<Board> gameBoard;
			Interface gameInterface;
			std::array<Player, 2> players;
			difficulties difficulty;
			gameModes gameMode;

	// members
		public:
			void initialize();
		// protected
		private:
			Game();
			~Game();
			void gameLoop();
			// préparation
				void initializeBoard();
				void initializePlayers();
				void initializeArmies();
				difficulties setDifficulty();
				gameModes setGameModes();
				unsigned int setWhoPlaysFirst();
};