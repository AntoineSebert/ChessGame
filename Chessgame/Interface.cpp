/*
	@author Antoine "Anthony" Sébert
	@creation_date 05/11/2017
	@description user input/output handler
*/

#include "Interface.h"

using namespace std;

// public
	unsigned int Interface::numberChoice(vector<string>* labels, unsigned int firstBound, unsigned int secondBound) {
		// must be at least a title and a possible answer
		if (labels->size() < 2)
			throw logic_error("The given array must at least contain two values");
		displayLabels(labels);
		return getNumberInput(firstBound, secondBound);
	}
	bool Interface::booleanChoice(vector<string>* labels) {
		displayLabels(labels);
		return getBooleanInput();
	}
	string Interface::alphanumericalChoice(vector<string>* labels) {
		displayLabels(labels);
		// put this constant in a header file
		return getStringInput(16);
	}
// protected
// private
	Interface::Interface() {}
	Interface::~Interface() {}
	void Interface::displayLabels(vector<string>* labels, unsigned int rows) {
		for (auto it = labels->begin(); it != labels->end(); ++it) {
			cout << ' ';
			if (*it != labels->front())
				cout << it - labels->begin() << " - ";
			cout << *it << endl;
		}
	}
	// first level input
		unsigned int Interface::getNumberInput(unsigned int firstBound, unsigned int secondBound) {
			string input;
			do {
				cout << " Please type a number between " << (secondBound == 0 ? 1 : firstBound) << " and " << (secondBound == 0 ? firstBound : secondBound) << " included" << endl;
				cin >> input;
			} while (!isNumberString(&input, firstBound, secondBound));
			return stoi(input) - 1;
		}
		bool Interface::getBooleanInput() {
			string input;
			do {
				cout << " Please type 0 or 1" << endl;
				cin >> input;
			} while (!isBoolean(&input));
			return stoi(input);
		}
		string Interface::getStringInput(unsigned int maxChararacters) {
			string input;
			do {
				cout << " Please type an alphanumerical string shorter than " << maxChararacters << " characters" << endl;
				cin >> input;
			} while (!isAlphanumeraicalString(&input) && maxChararacters < input.size());
			return input;
		}
	// second level input
		bool Interface::isNumberString(string* input, unsigned int firstBound, unsigned int secondBound) {
			for (auto character : *input) {
				if (!isNumber(character))
					return false;
			}
			unsigned int numberInput = stoi(*input);
			if (firstBound != 0)
				return (secondBound != 0 ? firstBound < numberInput && numberInput <= secondBound : 0 < numberInput && numberInput <= firstBound);
			return true;
		}
		bool Interface::isAlphabeticalString(string* input) {
			for (auto character : *input) {
				if (!isAlphabetical(character))
					return false;
			}
			return true;
		}
		bool Interface::isAlphanumeraicalString(string* input) {
			for (auto character : *input) {
				if (!isNumber(character) || !isAlphabetical(character))
					return false;
			}
			return true;
		}
		bool Interface::isBoolean(string* input) {
			return (input->size() == 1 && isNumberString(input) && input->front() < 32 ? *input == "1" : false);
		}
	// third level input
		bool Interface::isNumber(char character) {
			return 47 < character && character < 58;
		}
		bool Interface::isAlphabetical(char character) {
			return (64 < character && character < 91) || (96 < character && character < 123);
		}