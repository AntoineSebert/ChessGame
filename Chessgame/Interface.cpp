/*
	@author Antoine "Anthony" Sébert
	@creation_date 05/11/2017
	@description user input/output handler
*/

#include "Interface.h"

// public
	template<typename T>
	inline T Interface::multipleChoice(unsigned int choicesNumber, std::vector<std::string>* labels) {
		if (2 < labels->size()) {
			std::cout << ' ' << labels->at(0) << std::endl << std::endl;
			for (size_t i = 1; i < choicesNumber; ++i)
				std::cout << "  " << labels->at(i + 1) << std::endl << std::endl;
			return getCorrectInput(isNumberString);
		}
		return nullptr;
	}
	bool Interface::booleanChoice(std::string question) {
		std::cout << ' ' << question << std::endl << std::endl;
		return false;
	}

	// protected
// private
	Interface::Interface() {}
	Interface::~Interface() {}
	unsigned int Interface::getCorrectInput(unsigned int choicesNumber, bool(*testFunction)(std::string*)) {
		std::string input;
		do {
			std::cin >> input;
		} while (!isValueCorrect(&input, choicesNumber, testFunction));
		return 0;
	}
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
	bool Interface::isNumber(char character) {
		return 47 < character && character < 58;
	}
	bool Interface::isAlphabetical(char character) {
		return (64 < character && character < 91) || (96 < character && character < 123);
	}
	bool Interface::isValueCorrect(std::string* input, unsigned int choicesNumber, bool(*testFunction)(std::string*)) {
		if (testFunction(input)) {
			int result = std::stoi(*input);
			return 0 < result && result < (int)choicesNumber;
		}
		return false;
	}
