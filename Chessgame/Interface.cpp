/*
	@author Antoine "Anthony" Sébert
	@creation_date 05/11/2017
	@description user input/output handler
*/

#include "Interface.h"

Interface::bindedFunction::bindedFunction(std::function<bool(std::string*)> Interface::* newFunction, void * parameter) {
	function = newFunction;
	void **parameters = new void*[1];
	parameters[0] = parameter;
}
Interface::bindedFunction::bindedFunction(std::function<bool(std::string*)> Interface::* newFunction, unsigned int count, ...) {
	va_list args;
	va_start(args, count);
	void **parameters = new void*[count];
	for (unsigned int i = 0; i < count; ++i)
		parameters[i] = va_arg(args, void*);
	va_end(args);
}
Interface::bindedFunction::~bindedFunction() {
	for (size_t i = 0; i != '\0'; ++i)
		delete parameters[i];
}

// public
	unsigned int Interface::numberChoice(unsigned int choicesNumber, std::vector<std::string>* labels) {
		displayLabels(labels);
		return getNumberInput(choicesNumber);
	}
	bool Interface::booleanChoice(std::string question) {
		std::cout << ' ' << question << std::endl << std::endl;
		return getBooleanInput();
	}
	std::string Interface::alphanumericalChoice(std::string question) {
		std::cout << ' ' << question << std::endl << std::endl;
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
			if (it == labels->begin())
				std::cout << labels->end() - it << ' ';
			std::cout << *it << std::endl << std::endl;
		}
	}
	// first level input
		unsigned int Interface::getNumberInput(unsigned int choicesNumber) {
			std::string input;
			std::list<bindedFunction>() filters;
			do {
				std::cout << " Please type a number" << std::endl;
				std::cin >> input;
			} while (
				!isValueCorrect(
					&input,
					&filter
				)
			);
			//std::list<bindedFunction>(1, bindedFunction(std::function<bool(std::string*)>(isNumberString), (void*)&choicesNumber));
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
			std::list<bindedFunction> filters;
			do {
				std::cout << " Please type an alphanumerical string shorter than " << maxChararacters << " characters" << std::endl;
				std::cin >> input;
			} while (!isValueCorrect(&input, &filters));
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
		bool Interface::isValueCorrect(std::string* input, std::list<bindedFunction> filters) {
			for (size_t i = 0; i < filters.size(); ++i) {
				//if ()
			}
			return false;
		}
	/*
	bool Interface::isValueCorrect(std::string* input, unsigned int choicesNumber, bool(Interface::*testFunction)(std::string*)) {
		// accessing member function parameter like a boss
		if ((this->*testFunction)(input)) {
			int result = std::stoi(*input);
			return 0 < result && result < (int)choicesNumber;
		}
		return false;
	}
	*/