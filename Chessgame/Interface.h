/*
	@author Antoine "Anthony" Sébert
	@creation_date 05/11/2017
	@description user input/output handler
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Singleton.h"

class Interface : public Singleton<Interface> {
	friend class Singleton<Interface>;
	// attributes
		// public
		// protected
		// private

	// members
		public:
			unsigned int numberChoice(unsigned int choicesNumber, std::vector<std::string>* labels);
			bool booleanChoice(std::string question);
			std::string alphanumericalChoice(std::string question);
		// protected
		private:
			Interface();
			~Interface();
			void displayLabels(std::vector<std::string>* labels);
			// first level input
				unsigned int getCorrectInput(unsigned int choicesNumber, bool(Interface::*testFunction)(std::string*));
				bool getBooleanInput();
				std::string getStringInput(unsigned int maxChararacters);
			// second level input
				bool isNumberString(std::string* input);
				bool isAlphabeticalString(std::string* input);
				bool isAlphanumeraicalString(std::string* input);
				bool isBoolean(std::string* input);
			// third level input
				bool isNumber(char character);
				bool isAlphabetical(char character);
				// fonction de l'apocalypse
				bool isValueCorrect(std::string* input/*, list of generic functions to check the input (order matter), each followed with potential parameters*/);

			bool isValueCorrect(std::string* input, unsigned int choicesNumber, bool(Interface::*testFunction)(std::string*));
};