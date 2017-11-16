/*
	@author Antoine "Anthony" Sébert
	@creation_date 05/11/2017
	@description game initializer and handler
*/

#include "Game.h"

// public
	void Game::initialize() {
		gameInterface = &Interface::getInstance();
		gameMode = setGameModes();
		initializePlayers();
		difficulty = setDifficulty();
		gameBoard = &gameBoard->getInstance();
		initializeBoard();
		initializeArmies();
		gameLoop();
	}
	difficulties Game::getDifficulty() { return difficulty; }
	gameModes Game::getGameMode() { return gameMode; }
// protected
// private
	Game::Game() {}
	Game::~Game() {}
	void Game::gameLoop() {
		while (turns < 500 || isGameFinished()) {
			++turns;
			gameBoard->display(turns);
		}
	}
	bool Game::isGameFinished() {
		// tester les deux rois
		return false;
	}
	// préparation
		gameModes Game::setGameModes() {
			std::vector<std::string> labels = {
				"Select the gamemode",
				"PVP",
				"PVE",
				"EVE"
			};
			return (gameModes)gameInterface->numberChoice(&labels, (unsigned int)labels.size() - 1);
		}
		void Game::initializePlayers() {
			std::array<std::string, 2> names;
			initializePlayersNames(&names);
			unsigned int firstToPlayIndex = setWhoPlaysFirst(&names);
			for (unsigned int i = 0; i < players.size(); ++i)
				players[i] = std::make_shared<Player>(names[i], (i == firstToPlayIndex ? 0 : 1));
			firstToPlay = players[firstToPlayIndex];
		}
		void Game::initializePlayersNames(std::array<std::string, 2>* names) {
			switch (gameMode) {
				case PVP:
					chooseHumanPlayerName(&names->at(0), &(std::vector<std::string>(names->begin(), names->end())));
					chooseHumanPlayerName(&names->at(1), &(std::vector<std::string>(names->begin(), names->end())));
					break;
				case PVE:
					names->at(0) = "HAL9000";
					chooseHumanPlayerName(&names->at(1), &(std::vector<std::string>(names->begin(), names->end())));
					break;
				case EVE:
					for (unsigned int i = 0; i < players.size(); ++i)
						names->at(i) = "HAL9000";
					break;
			}
		}
		void Game::chooseHumanPlayerName(std::string* target, std::vector<std::string>* alreadyTakenNames) {
			do {
				*target = gameInterface->alphanumericalChoice(
					&(std::vector<std::string>() = {
					"Type the name of the human player (names must be different)"
				})
				);
			} while (std::find(alreadyTakenNames->begin(), alreadyTakenNames->end(), *target) != alreadyTakenNames->end());
		}
		unsigned int Game::setWhoPlaysFirst(std::array<std::string, 2>* names) {
			std::vector<std::string> labels = {
				"Select the player who will start playing first"
			};
			for (std::string name : *names)
				labels.push_back(name);
			return gameInterface->numberChoice(&labels, (unsigned int)labels.size() - 1);
		}
		difficulties Game::setDifficulty() {
			if (gameMode != PVP) {
				std::vector<std::string> labels = {
					"Select the difficulty",
					"RANDOM",
					"EASY",
					"MEDIUM",
					"HARD"
				};
				return (difficulties)gameInterface->numberChoice(&labels, (unsigned int)labels.size() - 1);
			}
			return NONE;
		}
		void Game::initializeBoard() {
			gameBoard->initialize();
		}
		void Game::initializeArmies() {
			for (unsigned int i = 0; i < players.size(); ++i)
				players.at(i).get()->initializeArmy(gameBoard);
		}