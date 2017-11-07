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
		// protected
		private:
			Interface();
			~Interface();
			bool isNumber(std::string input);
			bool isAlphabetical(std::string input);
			bool isAlphanumeraical(std::string input);
};