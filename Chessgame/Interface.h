/*
	@author Antoine "Anthony" Sébert
	@creation_date 05/11/2017
	@description user input/output handler
*/

#pragma once

#include <vector>
#include <string>

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
			bool isNumberString(std::string input);
			bool isAlphabeticalString(std::string input);
			bool isAlphanumeraicalString(std::string input);
			bool isNumber(char character);
			bool isAlphabetical(char character);
};