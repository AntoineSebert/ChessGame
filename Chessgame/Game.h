/*
	@author Antoine "Anthony" Sébert
	@creation_date 05/11/2017
	@description game initializer and handler
*/

#pragma once

#include <array>
#include <memory>
#include <string>
#include <vector>

#include "Singleton.h"
#include "difficulties.h"
#include "gameModes.h"
//#include "Board.h"
#include "Player.h"
#include "Interface.h"

class Game : public Singleton<Game> {
	friend class Singleton<Game>;
	// attributes
		// public
		// protected
		private:
			//std::unique_ptr<Board> gameBoard;
			Interface* gameInterface = nullptr;
			std::array<std::shared_ptr<Player>, 2> players;
			std::weak_ptr<Player> firstToPlay;
			difficulties difficulty;
			gameModes gameMode;

	// members
		public:
			void initialize();
			difficulties getDifficulty();
			gameModes getGameMode();
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