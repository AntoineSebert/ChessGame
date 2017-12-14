/*
	@author Antoine "Anthony" Sébert
	@creation_date 05/11/2017
	@description game initializer and handler
*/

#pragma once

#include <algorithm>
#include <array>
#include <list>
#include <memory>
#include <fstream>
#include <string>
#include <ctime>
#include <tuple>
#include <vector>
#include <GL\glew.h>
#include <GL\freeglut.h>

#include "Singleton.h"
#include "difficulties.h"
#include "gameModes.h"
#include "Board.h"
#include "Player.h"
#include "Interface.h"
#include "json.hpp"

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
			unsigned int turns = 0;
			std::list<std::tuple<boardCoord, boardCoord>> gameProgress;

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
			bool isGameFinished();
			std::weak_ptr<Player> selectPlayerToPlay(unsigned int turns);
			void reinitializeCallbacks();
			// import/ export
				void exportToFile();
				nlohmann::json convertToJson();
				bool importFile();
				std::string currentDatetimeToString();
				bool checkJSONValidity(nlohmann::json object);
			// préparation
				void initializeBoard();
				void initializePlayers();
				void initializePlayersNames(std::array<std::string, 2>* names);
				void chooseHumanPlayerName(std::string* target, std::vector<std::string>* alreadyTakenNames);
				unsigned int setWhoPlaysFirst(std::array<std::string, 2>* names);
				void initializeArmies();
				difficulties setDifficulty();
				gameModes setGameModes();
};