/*
	@author Antoine "Anthony" Sébert
	@creation_date 05/11/2017
	@description user input/output handler
*/

#include "Interface.h"

// public
	unsigned int Interface::numberChoice(unsigned int choicesNumber, std::vector<std::string>* labels) {
		displayLabels(labels);
		return getCorrectInput(choicesNumber, isNumberString);
	}
	bool Interface::booleanChoice(std::string question) {
		std::cout << ' ' << question << std::endl << std::endl;
		return getBooleanInput();
	}
	std::string Interface::alphanumericalChoice(std::string question) {
		std::cout << ' ' << question << std::endl << std::endl;
		// put this constant in a header file
		return getStringInput(32);
	}
// protected
// private
	Interface::Interface() {}
	Interface::~Interface() {}
	void Interface::displayLabels(std::vector<std::string>* labels) {
		for (std::vector<std::string>::iterator it = labels->begin(); it != labels->end(); ++it) {
			std::cout << ' ';
			if (it == labels->begin())
				std::cout << labels->end() - it << ' ';
			std::cout << *it << std::endl << std::endl;
		}
	}
	// first level input
		unsigned int Interface::getCorrectInput(unsigned int choicesNumber, bool(Interface::*testFunction)(std::string*)) {
			std::string input;
			do {
				//if (testFunction == &isNumberString)
				std::cout << " Please type a number" << std::endl;
				std::cin >> input;
			} while (!isValueCorrect(&input, choicesNumber, testFunction));
			return std::stoi(input);
		}
		bool Interface::getBooleanInput() {
			std::string input;
			do {
				std::cout << " Please type 0 or 1" << std::endl;
				std::cin >> input;
			} while (!isBoolean(&input));
			return std::stoi(input);
		}
		std::string Interface::getStringInput(unsigned int maxChararacters) {
			std::string input;
			do {
				std::cout << " Please type an alphanumerical string shorter than " << maxChararacters << " characters" << std::endl;
				std::cin >> input;
			} while (!isValueCorrect(&input, maxChararacters, testFunction));
			return input;
		}
	// second level input
		bool Interface::isNumberString(std::string* input) {
			for (size_t i = 0; i < input->size(); ++i) {
				if (!isNumber(input->at(i)))
					return false;
			}
			return true;
		}
		bool Interface::isAlphabeticalString(std::string* input) {
			for (size_t i = 0; i < input->size(); ++i) {
				if (!isAlphabetical(input->at(i)))
					return false;
			}
			return true;
		}
		bool Interface::isAlphanumeraicalString(std::string* input) {
			for (size_t i = 0; i < input->size(); ++i) {
				if (!isNumber(input->at(i)) || !isAlphabetical(input->at(i)))
					return false;
			}
			return true;
		}
		bool Interface::isBoolean(std::string* input) {
			return (input->size() == 1 && isNumberString(input) && input->front() < 32 ? *input == "1" : false);
		}
	// third level input
		bool Interface::isNumber(char character) {
			return 47 < character && character < 58;
		}
		bool Interface::isAlphabetical(char character) {
			return (64 < character && character < 91) || (96 < character && character < 123);
		}

	bool Interface::isValueCorrect(std::string* input, unsigned int choicesNumber, bool(Interface::*testFunction)(std::string*)) {
		// accessing member function parameter like a boss
		if ((this->*testFunction)(input)) {
			int result = std::stoi(*input);
			return 0 < result && result < (int)choicesNumber;
		}
		return false;
	}
