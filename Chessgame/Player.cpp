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
	void Player::initializeArmy(Board* gameBoard, unsigned int start, unsigned int end) {
		playerArmy = std::make_unique<Army>(&color);
		// boucle for pour la mise en place des pièces
		//playerArmy.get().
	}
// protected
// private
