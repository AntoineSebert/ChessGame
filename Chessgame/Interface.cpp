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
			for (unsigned int i = 1; i < choicesNumber; ++i)
				std::cout << "  " << labels->at(i + 1) << std::endl << std::endl;
		}
		//cin >>
		return nullptr;
	}

	bool Interface::booleanChoice(std::vector<std::string>* labels) {
		return false;
	}

	// protected
// private
	Interface::Interface() {}
	Interface::~Interface() {}

	bool Interface::isNumber(std::string input) {
		return false;
	}

	bool Interface::isAlphabetical(std::string input) {
		return false;
	}

	bool Interface::isAlphanumeraical(std::string input) {
		return false;
	}
