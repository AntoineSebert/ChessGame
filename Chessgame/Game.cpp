/*
	@author Antoine "Anthony" S�bert
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
// protected
// private
	Game::Game() {
		gameInterface = &Interface::getInstance();
	}
	Game::~Game() {}
	void Game::gameLoop() {}
	// pr�paration
		gameModes Game::setGameModes() {
			/*
			switch (gameInterface) {

			}
			*/
			return gameModes();
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