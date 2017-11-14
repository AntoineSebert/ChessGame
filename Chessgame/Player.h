/*
	@author Antoine "Anthony" Sébert
	@creation_date 06/11/2017
	@description player
*/

#pragma once

#include <memory>
#include <iostream>
#include <string>

#include "Army.h"
#include "Board.h"

class Player {
	// attributes
		private:
			std::unique_ptr<Army> playerArmy;
			unsigned int color;
			std::string name;

	// members
		public:
			Player(std::string playerName, unsigned int newColor);
			~Player();
			std::string getName();
			unsigned int getColor();
			void initializeArmy(Board* gameBoard, unsigned int start, unsigned int end);
		// protected
		// private
};