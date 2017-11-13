/*
	@author Antoine "Anthony" Sébert
	@creation_date 05/11/2017
	@description user input/output handler
*/

#include "Interface.h"

// public
	unsigned int Interface::numberChoice(std::vector<std::string>* labels, unsigned int firstBound, unsigned int secondBound) {
		if (labels->size() < 2)
			throw std::logic_error("The given array must at least contain two values");
		displayLabels(labels);
		return getNumberInput(firstBound, secondBound);
	}
	bool Interface::booleanChoice(std::vector<std::string>* labels) {
		displayLabels(labels);
		return getBooleanInput();
	}
	std::string Interface::alphanumericalChoice(std::vector<std::string>* labels) {
		displayLabels(labels);
		// put this fucking constant in a header file
		return getStringInput(32);
	}
// protected
// private
	Interface::Interface() {}
	Interface::~Interface() {}
	void Interface::displayLabels(std::vector<std::string>* labels) {
		for (std::vector<std::string>::iterator it = labels->begin(); it != labels->end(); ++it) {
			std::cout << ' ';
			if (*it != labels->front())
				std::cout << it - labels->begin() << " - ";
			std::cout << *it << std::endl << std::endl;
		}
	}
	// first level input
		unsigned int Interface::getNumberInput(unsigned int firstBound, unsigned int secondBound) {
			std::string input;
			do {
				std::cout << " Please type a number between " << (secondBound == 0 ? 1 : firstBound) << " and " << (secondBound == 0 ? firstBound : secondBound) << " included" << std::endl;
				std::cin >> input;
			} while (!isNumberString(&input, firstBound, secondBound));
			return std::stoi(input) - 1;
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
			} while (!isAlphanumeraicalString(&input) && maxChararacters < input.size());
			return input;
		}
	// second level input
		bool Interface::isNumberString(std::string* input, unsigned int firstBound, unsigned int secondBound) {
			for (size_t i = 0; i < input->size(); ++i) {
				if (!isNumber(input->at(i)))
					return false;
			}
			unsigned int numberInput = std::stoi(*input);
			if (firstBound != 0)
				return (secondBound != 0 ? firstBound < numberInput && numberInput <= secondBound : 0 < numberInput && numberInput <= firstBound);
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