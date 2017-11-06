#pragma once

#include "Singleton.h"

/*
	@author Antoine "Anthony" S�bert
	@creation_date 05/11/2017
	@description user input handler
*/

class Interface : public Singleton<Interface> {
	friend class Singleton<Interface>;
	private:
	Interface();
	~Interface();
};

