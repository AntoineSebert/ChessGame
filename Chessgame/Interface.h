/*
	@author Antoine "Anthony" S�bert
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
			unsigned int getCorrectInput(unsigned int choicesNumber, bool(*testFunction)(std::string));
			bool isNumberString(std::string input);
			bool isAlphabeticalString(std::string input);
			bool isAlphanumeraicalString(std::string input);
			bool isNumber(char character);
			bool isAlphabetical(char character);
};