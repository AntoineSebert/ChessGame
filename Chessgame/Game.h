/*
	@author Antoine "Anthony" Sébert
	@creation_date 05/11/2017
	@description game initializer and handler
*/

#pragma once

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "Singleton.h"
#include "difficulties.h"
#include "gameModes.h"
#include "Board.h"
#include "Player.h"
#include "Interface.h"

class Game : public Singleton<Game> {
	friend class Singleton<Game>;
	// attributes
		private:
			Board* gameBoard = nullptr;
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
			void chooseHumanPlayerName(std::string* target, std::vector<std::string>* alreadyTakenNames);
			// préparation
				void initializeBoard();
				void initializePlayers();
				void initializePlayersNames(std::array<std::string, 2>* names);
				unsigned int setWhoPlaysFirst(std::array<std::string, 2>* names);
				void initializeArmies();
				difficulties setDifficulty();
				gameModes setGameModes();
};