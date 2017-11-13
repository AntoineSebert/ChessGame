/*
	@author Antoine "Anthony" Sébert
	@creation_date 06/11/2017
	@description player
*/

#pragma once

#include <iostream>
#include <string>

#include "Army.h"

class Player {
	// attributes
		private:
			Army playerArmy;
			unsigned int color;
			std::string name;

	// members
		public:
			Player(std::string playerName, unsigned int newColor);
			~Player();
			std::string getName();
			unsigned int getColor();
			void initializeArmy();
		// protected
		// private
};