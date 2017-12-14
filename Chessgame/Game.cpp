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
			// select next player to play, make him play, record move
			gameProgress.push_back(selectPlayerToPlay(turns).lock()->play(gameBoard));
		}
	}
	bool Game::isGameFinished() {
		// end of game tests
		return false;
	}
	weak_ptr<Player> Game::selectPlayerToPlay(unsigned int turns) {
		// works for a number N of players
		return players.at(turns % players.size());
	}
	void Game::reinitializeCallbacks() {
		glutDisplayFunc(NULL);
		glutMouseFunc(NULL);
		glutMotionFunc(NULL);
		glutPassiveMotionFunc(NULL);
	}
	// import / export
		void Game::exportToFile() {
			json container = convertToJson();
			// creation of the output stream
			ofstream o("output.json");
			// formatting and writing
			o << setw(4) << container << endl;
		}
		json Game::convertToJson() {
			json container;
			// date time
			container["date"] = currentDatetimeToString();
			// players
			container["players"] = json::array();
			for (shared_ptr<Player> player : players)
				container["players"].push_back(player->getName());
			// first player to play
			container["firstPlayerToPlay"] = firstToPlay.lock()->getName();
			// moves
			container["progress"] = json::array();
			for (tuple<boardCoord, boardCoord> move : gameProgress)
				container["progress"].push_back(move);
			return container;
		}
		bool Game::importFile() {
			// creation of the input stream
			ifstream i("input.json");
			json container;
			// writing data into container
			i >> container;
			// check if input is correct
			if (!checkJSONValidity(container))
				return false;
			// do not write in object member 'gameProgress' yet, but in temporary variable
			list<tuple<boardCoord, boardCoord>> temp;
			for (unsigned int i = 0; i < players.size(); ++i)
				players.at(i) = make_shared<Player>(container["players"].at(i), (container["players"].at(i) == container["firstPlayerToPlay"] ? 0 : 1), gameInterface);
			// copying moves
			for (json move : container["progress"]) {
				if (move.is_array())
					temp.push_back(
						forward_as_tuple(
							forward_as_tuple(move.at(0).at(0), move.at(0).at(1)),
							forward_as_tuple(move.at(1).at(0), move.at(1).at(1))
						)
					);
				else
					return false;
			}
			// clear the member
			gameProgress.clear();
			// copying the data
			copy(temp.begin(), temp.end(), gameProgress.begin());
			return true;
		}
		string Game::currentDatetimeToString() {
			// time container
			time_t rawtime;
			// put  urrent time into container
			time(&rawtime);
			// time information container
			struct tm timeinfo;
			// put human-readable datetime in time information container
			localtime_s(&timeinfo, &rawtime);
			// creating the buffer with sufficient space
			char buffer[80];
			// convert time to a sequence of characters
			strftime(buffer, 80, "%c", &timeinfo);
			return buffer;
		}
		bool Game::checkJSONValidity(json object) {
			// check of required objects exists
			if (
				object.find("date") != object.end() &&
				object.find("players") != object.end() &&
				object.find("firstPlayerToPlay") != object.end() &&
				object.find("progress") != object.end()
				) {
				// check the types & contents
				if (
					object["players"].is_array() && object["players"].size() == 2 &&
					object["date"].is_string() && object["date"].is_null() &&
					object["firstPlayerToPlay"].is_string() && object["firstPlayerToPlay"].is_null() &&
					object["progress"].is_array() && !object["players"].empty()
					)
					return true;
			}
			return false;
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
			// creating an array for the names
			array<string, 2> names;
			// fill array with players names
			initializePlayersNames(&names);
			// select the player to play first from the names array
			unsigned int firstToPlayIndex = setWhoPlaysFirst(&names);
			// creating the players objects in the member 'players'
			for (unsigned int i = 0; i < players.size(); ++i)
				players[i] = make_shared<Player>(names[i], (i == firstToPlayIndex ? 0 : 1), gameInterface);
			// setting the pointer to the player to play first
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
			// while the chosen name already exists, choose an other name
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
			// if two humans are playing, difficulty is not needed
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