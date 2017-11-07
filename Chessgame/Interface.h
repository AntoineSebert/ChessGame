/*
	@author Antoine "Anthony" Sébert
	@creation_date 05/11/2017
	@description user input handler
*/

#pragma once

#include "Singleton.h"

class Interface : public Singleton<Interface> {
	friend class Singleton<Interface>;
	// attributes
		// public
		// protected
		// private

	// members
		// public
		// protected
		private:
			Interface();
			~Interface();
};

