/*
	@author Antoine "Anthony" Sébert
	@creation_date 05/11/2017
	@description user input handler
*/

#pragma once

#include <list>
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
			template<typename T> T multipleChoice(unsigned int choicesNumber, std::list<std::string>* labels);
		// protected
		private:
			Interface();
			~Interface();
};

template<typename T>
inline T Interface::multipleChoice(unsigned int choicesNumber, std::list<std::string>* labels) {
	return T();
}
