#include "Game.h"

/*
	@author Antoine "Anthony" S�bert
	@creation_date 05/11/2017
	@description game initializer and handler
*/

// public
	void Game::initialize() {
		initializeBoard();
		gameMode = setGameModes();
		difficulty = setDifficulty();
		initializePlayers();
		setWhoPlaysFirst();
		initializeArmies();
	}
	// protected
// private
	void Game::gameLoop() {}
	// pr�paration
		void Game::initializeBoard() {
			gameBoard.get()->getInstance();
		}
		void Game::initializePlayers() {}
		void Game::initializeArmies() {}
		difficulties Game::setDifficulty() {

			return difficulties();
		}
		gameModes Game::setGameModes() {
			return gameModes();
		}

		unsigned int Game::setWhoPlaysFirst() {
			return 0;
		}
