/*
	@author Antoine "Anthony" Sébert
	@creation_date 05/11/2017
	@description user input/output handler
*/

#pragma once

#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include "Singleton.h"

class Interface : public Singleton<Interface> {
	friend class Singleton<Interface>;
	// attributes
		// private

	// members
		public:
			unsigned int numberChoice(std::vector<std::string>* labels, unsigned int firstBound, unsigned int secondBound = 0);
			bool booleanChoice(std::vector<std::string>* labels);
			std::string alphanumericalChoice(std::vector<std::string>* labels);
		// protected
		private:
			Interface();
			~Interface();
			void displayLabels(std::vector<std::string>* labels);
			// first level input
				unsigned int getNumberInput(unsigned int firstBound, unsigned int secondBound = 0);
				bool getBooleanInput();
				std::string getStringInput(unsigned int maxChararacters);
			// second level input
				bool isNumberString(std::string* input, unsigned int firstBound = 0, unsigned int secondBound = 0);
				bool isAlphabeticalString(std::string* input);
				bool isAlphanumeraicalString(std::string* input);
				bool isBoolean(std::string* input);
			// third level input
				bool isNumber(char character);
				bool isAlphabetical(char character);
};