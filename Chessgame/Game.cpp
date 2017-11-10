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
		setWhoPlaysFirst();
		initializeBoard();
		initializeArmies();
	}
	difficulties Game::getDifficulty() { return difficulty; }
	gameModes Game::getGameMode() { return gameMode; }
// protected
// private
	Game::Game() {}
	Game::~Game() {}
	void Game::gameLoop() {}
	// préparation
		gameModes Game::setGameModes() {
			std::vector<std::string> labels = {
				"Select the gamemode",
				"PVP",
				"PVE",
				"EVE"
			};
			return (gameModes)gameInterface->numberChoice(&labels, EVE + 1);
		}
		void Game::initializePlayers() {

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
				return (difficulties)gameInterface->numberChoice(&labels, HARD + 1);
			}
			return NONE;
		}
		unsigned int Game::setWhoPlaysFirst() {
			return 0;
		}
		void Game::initializeBoard() {
			//gameBoard.get()->getInstance();
		}
		void Game::initializeArmies() {}