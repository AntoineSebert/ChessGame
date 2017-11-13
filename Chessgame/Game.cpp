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
		initializeBoard();
		initializeArmies();
	}
	difficulties Game::getDifficulty() { return difficulty; }
	gameModes Game::getGameMode() { return gameMode; }
// protected
// private
	Game::Game() {}
	Game::~Game() {
	}
	void Game::gameLoop() {}
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
			switch (gameMode) {
				case PVP:
					for(unsigned int i = 0; i < players.size(); ++i)
						players[i] = std::make_shared<Player>(Player("HAL9000", 2));
					break;
				case PVE:
					for (unsigned int i = 0; i < players.size(); ++i)
						players[i] = std::make_shared<Player>(Player("HAL9000", 2));
					break;
				case EVE:
					for (unsigned int i = 0; i < players.size(); ++i)
						players[i] = std::make_shared<Player>(Player("HAL9000", 2));
					break;
				default:
					break;
			}
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
			return players.at(gameInterface->numberChoice(&labels, labels.size() - 1));
		}
		void Game::initializeBoard() {
			//gameBoard.get()->getInstance();
		}
		void Game::initializeArmies() {}