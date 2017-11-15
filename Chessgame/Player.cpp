/*
	@author Antoine "Anthony" Sébert
	@creation_date 06/11/2017
	@description player
*/

#include "Player.h"

// public
	Player::Player(std::string playerName, unsigned int newColor) {
		name = playerName;
		color = newColor;
	}
	Player::~Player() {}
	std::string Player::getName() { return name; }
	unsigned int Player::getColor() { return color; }
	void Player::initializeArmy(Board* gameBoard) {
		playerArmy = std::make_unique<Army>(&color);
		if (color == 0) {

			for (unsigned int i = 0; i < playerArmy.get()->getArmySize(); ++i) {
				playerArmy.get()->getPiecesInArmy();
			}
		}
		else {

		}
	}
// protected
// private
