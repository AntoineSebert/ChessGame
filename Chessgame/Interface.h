/**
	@author Antoine "Anthony" Sébert
	@creation_date 05/11/2017
	@description user input/output handler
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <GL\glew.h>
#include <GL\freeglut.h>

#include "Singleton.h"
#include "Piece.h"

class Interface : public Singleton<Interface> {
	friend class Singleton<Interface>;
	// members
		public:
			unsigned int numberChoice(std::vector<std::string>* labels, unsigned int firstBound, unsigned int secondBound = 0);
			bool booleanChoice(std::vector<std::string>* labels);
			std::string alphanumericalChoice(std::vector<std::string>* labels);
		private:
			Interface();
			~Interface();
			void displayLabels(std::vector<std::string>* labels, unsigned int rows = 0);
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