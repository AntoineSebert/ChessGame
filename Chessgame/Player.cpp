/*
	@author Antoine "Anthony" Sébert
	@creation_date 06/11/2017
	@description player
*/

#include "Player.h"

// public
	Player::Player(std::string playerName, unsigned int newColor) : name(playerName), color(newColor) {}
	Player::~Player() {}
	std::string Player::getName() { return name; }
// protected
// private
