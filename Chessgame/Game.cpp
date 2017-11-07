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
// protected
// private
	void Game::gameLoop() {}
	// préparation
		void Game::initializePlayers() {

		}
		difficulties Game::setDifficulty() {

			return difficulties();
		}
		gameModes Game::setGameModes() {
			return gameModes();
		}
		unsigned int Game::setWhoPlaysFirst() {
			return 0;
		}
		void Game::initializeBoard() {
			//gameBoard.get()->getInstance();
		}
		void Game::initializeArmies() {}
		Game::Game() {}
		Game::~Game() {}