/*
	@author Antoine "Anthony" Sébert
	@creation_date 05/11/2017
	@description user input/output handler
*/

#pragma once

#include <cstdarg>
#include <functional>
#include <iostream>
#include <list>
#include <string>
#include <vector>

#include "Singleton.h"

class Interface : public Singleton<Interface> {
	friend class Singleton<Interface>;
	// attributes
		// public
		// protected
		// private
			struct bindedFunction {
				public:
					// equivalent to void* array[] -> language security bypass like a boss
					void** parameters;
					std::function<bool(std::string*)>Interface::* function;
					bindedFunction(std::function<bool(std::string*)>Interface::* newFunction, void* parameter);
					bindedFunction(std::function<bool(std::string*)>Interface::* newFunction, unsigned int count, ...);
					~bindedFunction();
			};

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
				unsigned int getNumberInput(unsigned int choicesNumber);
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
				bool isValueCorrect(std::string* input, std::list<std::function<bool(std::string*)>Interface::*> functions, std::list<int*> arguments = {});
};