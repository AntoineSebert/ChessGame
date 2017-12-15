/*! \class		Game
	\author		Antoine "Anthony" Sébert
	\date		05/11/2017
	\brief		Game initializer and handler.
	\details	Holds the board, the players, the game parameters & moves. Order the initialization of each element. Handle the game loop.
*/

#pragma once

#include <array>
#include <ctime>
#include <fstream>
#include <list>
#include <memory>
#include <string>
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
#include "glut.h"

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
		private:
			Game();
			~Game();
			void gameLoop();
			bool isGameFinished();
			std::weak_ptr<Player> selectPlayerToPlay(unsigned int turns);
			void reinitializeCallbacks();
			void displayBoard();
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