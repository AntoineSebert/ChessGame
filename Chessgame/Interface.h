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
#include "Piece.h"

using namespace std;

class Interface : public Singleton<Interface> {
	friend class Singleton<Interface>;
	// members
		public:
			unsigned int numberChoice(vector<string>* labels, unsigned int firstBound, unsigned int secondBound = 0);
			bool booleanChoice(vector<string>* labels);
			string alphanumericalChoice(vector<string>* labels);
		private:
			Interface();
			~Interface();
			void displayLabels(vector<string>* labels, unsigned int rows = 0);
			// first level input
				unsigned int getNumberInput(unsigned int firstBound, unsigned int secondBound = 0);
				bool getBooleanInput();
				string getStringInput(unsigned int maxChararacters);
			// second level input
				bool isNumberString(string* input, unsigned int firstBound = 0, unsigned int secondBound = 0);
				bool isAlphabeticalString(string* input);
				bool isAlphanumeraicalString(string* input);
				bool isBoolean(string* input);
			// third level input
				bool isNumber(char character);
				bool isAlphabetical(char character);
};