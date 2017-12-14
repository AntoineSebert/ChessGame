/*
	@author Antoine "Anthony" Sébert
	@creation_date 05/11/2017
	@description game initializer and handler
*/

#include "Game.h"

using namespace std;
using json = nlohmann::json;

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
		exportToFile();
	}
	difficulties Game::getDifficulty() { return difficulty; }
	gameModes Game::getGameMode() { return gameMode; }
// protected
// private
	Game::Game() {}
	Game::~Game() {}
	void Game::gameLoop() {
		while (turns < 2 || isGameFinished()) {
			++turns;
			gameBoard->display(turns);
			gameProgress.push_back(selectPlayerToPlay(turns).lock()->play(gameBoard));
		}
	}
	bool Game::isGameFinished() {
		// tester les deux rois, si les pièces peuvent bouger, et d'autres trucs
		return false;
	}
	std::weak_ptr<Player> Game::selectPlayerToPlay(unsigned int turns) {
		return players.at(turns % players.size());
	}
	void Game::reinitializeCallbacks() {
		glutDisplayFunc(NULL);
		glutMouseFunc(NULL);
		glutMotionFunc(NULL);
		glutPassiveMotionFunc(NULL);
	}
	// import/ export
		bool Game::exportToFile() {
			json container = convertToJson();
			cout << container.dump(4) << endl;
			ofstream o("output.json");
			o << std::setw(4) << container << endl;
			return false;
		}
		json Game::convertToJson() {
			json container;
			container["date"] = currentDatetimeToString();
			container["players"] = json::array();
			for (shared_ptr<Player> player : players)
				container["players"].push_back(player->getName());
			container["progress"] = json::array();
			for (tuple<boardCoord, boardCoord> move : gameProgress)
				container["progress"].push_back(move);
			return container;
		}
		bool Game::importFile() {
			/*
			std::ifstream i("file.json");
			json j;
			i >> j;
			*/
			return false;
		}
		std::string Game::currentDatetimeToString() {
			time_t rawtime;
			time(&rawtime);
			struct tm timeinfo;
			localtime_s(&timeinfo, &rawtime);
			char buffer[80];
			strftime(buffer, 80, "%c", &timeinfo);
			return buffer;
		}
	// préparation
		gameModes Game::setGameModes() {
			vector<string> labels = {
				"Select the gamemode",
				"PVP",
				"PVE",
				"EVE"
			};
			glutDisplayFunc(drawDifficultyMenu);
			glutMouseFunc(difficutyMenuClick);
			//glutMotionFunc(); // button held down
			//glutPassiveMotionFunc(); // no button held down
			return EVE;
		}
		void Game::initializePlayers() {
			array<string, 2> names;
			initializePlayersNames(&names);
			unsigned int firstToPlayIndex = setWhoPlaysFirst(&names);
			for (unsigned int i = 0; i < players.size(); ++i)
				players[i] = make_shared<Player>(names[i], (i == firstToPlayIndex ? 0 : 1), gameInterface);
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