/*
	@author Antoine "Anthony" Sébert
	@creation_date 05/11/2017
	@description game initializer and handler
*/

#include "Game.h"

// public
	void Game::initialize() {
		gameMode = setGameModes();
		difficulty = setDifficulty();
		initializePlayers();
		setWhoPlaysFirst();
		initializeBoard();
		initializeArmies();
	}
	difficulties Game::getDifficulty() { return difficulty; }
	gameModes Game::getGameModes() { return gameMode; }
// protected
// private
	Game::Game() {
		gameInterface = &Interface::getInstance();
	}
	Game::~Game() {}
	void Game::gameLoop() {}
	// préparation
		gameModes Game::setGameModes() {
			std::vector<std::string> labels = {
				"Select the gamemode",
				"1 - PVP",
				"2 - PVE",
				"3 - EVE"
			};
			return (gameModes)gameInterface->numberChoice(&labels, EVE + 1);
		}
		void Game::initializePlayers() {

		}
		difficulties Game::setDifficulty() {

			return difficulties();
		}
		unsigned int Game::setWhoPlaysFirst() {
			return 0;
		}
		void Game::initializeBoard() {
			//gameBoard.get()->getInstance();
		}
		void Game::initializeArmies() {}