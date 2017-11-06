#pragma once

#include "Singleton.h"

/*
	@author Antoine "Anthony" Sébert
	@creation_date 06/11/2017
	@description game board container
*/

class Board : public Singleton<Board> {
	friend class Singleton<Board>;
	private:
		Board();
		~Board();
};

