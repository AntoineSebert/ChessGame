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
		while (turns < 5 || isGameFinished()) {
			++turns;
			gameBoard->display(turns);
			selectPlayerToPlay(turns);
		}
	}
	bool Game::isGameFinished() {
		// tester les deux rois, si les pièces peuvent bouger, et d'autres trucs
		return false;
	}
	void Game::selectPlayerToPlay(unsigned int turns) {
		players.at(turns % players.size())->play();
	}
	// préparation
		gameModes Game::setGameModes() {
			vector<string> labels = {
				"Select the gamemode",
				"PVP",
				"PVE",
				"EVE"
			};
			return (gameModes)gameInterface->numberChoice(&labels, (unsigned int)labels.size() - 1);
		}
		void Game::initializePlayers() {
			array<string, 2> names;
			initializePlayersNames(&names);
			unsigned int firstToPlayIndex = setWhoPlaysFirst(&names);
			for (unsigned int i = 0; i < players.size(); ++i)
				players[i] = make_shared<Player>(names[i], (i == firstToPlayIndex ? 0 : 1));
			firstToPlay = players[firstToPlayIndex];
		}
		void Game::initializePlayersNames(array<string, 2>* names) {
			switch (gameMode) {
				case PVP:
					chooseHumanPlayerName(&names->at(0), &(vector<string>(names->begin(), names->end())));
					chooseHumanPlayerName(&names->at(1), &(vector<string>(names->begin(), names->end())));
					break;
				case PVE:
					names->at(0) = "HAL9000";
					chooseHumanPlayerName(&names->at(1), &(vector<string>(names->begin(), names->end())));
					break;
				case EVE:
					for (unsigned int i = 0; i < players.size(); ++i)
						names->at(i) = "HAL9000";
					break;
			}
		}
		void Game::chooseHumanPlayerName(string* target, vector<string>* alreadyTakenNames) {
			do {
				*target = gameInterface->alphanumericalChoice(
					&(vector<string>() = {
					"Type the name of the human player (names must be different)"
				})
				);
			} while (find(alreadyTakenNames->begin(), alreadyTakenNames->end(), *target) != alreadyTakenNames->end());
		}
		unsigned int Game::setWhoPlaysFirst(array<string, 2>* names) {
			vector<string> labels = {
				"Select the player who will start playing first"
			};
			for (auto name : *names)
				labels.push_back(name);
			return gameInterface->numberChoice(&labels, (unsigned int)labels.size() - 1);
		}
		difficulties Game::setDifficulty() {
			if (gameMode != PVP) {
				vector<string> labels = {
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
				players.at(i)->initializeArmy(gameBoard);
		}