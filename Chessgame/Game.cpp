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
		std::cout << "============" << std::endl;
		setWhoPlaysFirst();
		std::cout << "============" << std::endl;
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
		for (std::shared_ptr<Player> player : players)
			player.reset();
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
					break;
				case PVE:
					break;
				case EVE:
					for (std::shared_ptr<Player> player : players)
						player = std::make_shared<Player>(Player("HAL9000", 2));
					firstToPlay = std::static_pointer_cast<Player>(players.at(0));
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
		unsigned int Game::setWhoPlaysFirst() {
			std::vector<std::string> labels = {
				"Select the player who will start playing first"
			};
			players.at(0).get()->getName();
			/*
			for (std::shared_ptr<Player> player : players)
				labels.push_back(player.get()->getName());
			*/
			//return gameInterface->numberChoice(&labels, labels.size() - 1);
			return 0;
		}
		void Game::initializeBoard() {
			//gameBoard.get()->getInstance();
		}
		void Game::initializeArmies() {}