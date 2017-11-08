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
			template<typename T>
			T multipleChoice(unsigned int choicesNumber, std::vector<std::string>* labels);
			bool booleanChoice(std::string question);
		// protected
		private:
			Interface();
			~Interface();
			void displayLabels(std::vector<std::string>* labels);
			unsigned int getCorrectInput(unsigned int choicesNumber, bool(Interface::*testFunction)(std::string*));
			bool getBooleanInput();
			bool isNumberString(std::string* input);
			bool isAlphabeticalString(std::string* input);
			bool isAlphanumeraicalString(std::string* input);
			bool isBoolean(std::string* input);
			bool isNumber(char character);
			bool isAlphabetical(char character);
			bool isValueCorrect(std::string* input, unsigned int choicesNumber, bool(Interface::*testFunction)(std::string*));
};