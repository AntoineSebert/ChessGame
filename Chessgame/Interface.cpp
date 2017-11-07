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
		}
		//cin >>
		return nullptr;
	}

	bool Interface::booleanChoice(std::string question) {
		return false;
	}

	// protected
// private
	Interface::Interface() {}
	Interface::~Interface() {}
	bool Interface::isNumberString(std::string input) {
		for (size_t i = 0; i < input.length; ++i) {
			if (!isNumber(input.at(i)))
				return false;
		}
		return true;
	}
	bool Interface::isAlphabeticalString(std::string input) {
		for (size_t i = 0; i < input.length; ++i) {
			if (!isAlphabetical(input.at(i)))
				return false;
		}
		return true;
	}
	bool Interface::isAlphanumeraicalString(std::string input) {
		for (size_t i = 0; i < input.length; ++i) {
			if (!isNumber(input.at(i)) || !isAlphabetical(input.at(i)))
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
