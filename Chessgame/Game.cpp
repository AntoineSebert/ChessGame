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
		firstToPlay = setWhoPlaysFirst();
		difficulty = setDifficulty();

		gameBoard = &gameBoard->getInstance();
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
	void Game::chooseHumanPlayerName(std::string* target, std::vector<std::string>* alreadyTakenNames) {
		do {
			*target = gameInterface->alphanumericalChoice(
				&(std::vector<std::string>() = {
					"Type the name of the human player (names must be different)"
				})
			);
		} while (std::find(alreadyTakenNames->begin(), alreadyTakenNames->end(), *target) != alreadyTakenNames->end());
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
			switch (gameMode) {
				case PVP:
					chooseHumanPlayerName(&names[0], &(std::vector<std::string>(names.begin(), names.end())));
					chooseHumanPlayerName(&names[1], &(std::vector<std::string>(names.begin(), names.end())));
					break;
				case PVE:
					names[0] = "HAL9000";
					chooseHumanPlayerName(&names[1], &(std::vector<std::string>(names.begin(), names.end())));
					break;
				case EVE:
					for (unsigned int i = 0; i < players.size(); ++i)
						names[i] = "HAL9000";
					break;
				default:
					break;
			}
			for (unsigned int i = 0; i < players.size(); ++i)
				players[i] = std::make_shared<Player>(Player(names[i], 2));
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
		std::shared_ptr<Player> Game::setWhoPlaysFirst() {
			std::vector<std::string> labels = {
				"Select the player who will start playing first"
			};
			for (std::shared_ptr<Player> player : players)
				labels.push_back(player->getName());
			return players.at(gameInterface->numberChoice(&labels, (unsigned int)labels.size() - 1));
		}
		void Game::initializeBoard() {
			gameBoard->initialize();
		}
		void Game::initializeArmies() {}