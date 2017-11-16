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
		playerArmy.get()->displayArmy();
		if (color == 0) {
			placePieces(
				gameBoard->getData()->at(1).begin(), gameBoard->getData()->at(1).end(),
				playerArmy.get()->getArmyContainer()->begin() + 8, playerArmy.get()->getArmyContainer()->end()
			);
			placePieces(
				gameBoard->getData()->at(0).begin(), gameBoard->getData()->at(0).end(),
				playerArmy.get()->getArmyContainer()->begin(), playerArmy.get()->getArmyContainer()->end() - 8
			);
		}
		else {
			placePieces(
				gameBoard->getData()->at(6).begin(), gameBoard->getData()->at(6).end(),
				playerArmy.get()->getArmyContainer()->begin() + 8, playerArmy.get()->getArmyContainer()->end()
			);
			placePieces(
				gameBoard->getData()->at(7).begin(), gameBoard->getData()->at(7).end(),
				playerArmy.get()->getArmyContainer()->begin(), playerArmy.get()->getArmyContainer()->end() - 8
			);
		}
	}
// protected
// private
	void Player::placePieces(
		std::array<Cell*, 8>::iterator cellStart, std::array<Cell*, 8>::iterator cellEnd,
		std::vector<std::shared_ptr<Piece>>::iterator pieceStart, std::vector<std::shared_ptr<Piece>>::iterator pieceEnd
	) {
		if (cellEnd - cellStart == pieceEnd - pieceStart && cellStart < cellEnd && pieceStart < pieceEnd) {
			auto pieceIt = pieceStart;
			for (auto it = cellStart; it < cellEnd; ++it) {
				(*it)->setPiece(*pieceIt);
				if (pieceIt != pieceEnd)
					++pieceIt;
			}
		}
		else {
			perror("The given intervals does not match");
			std::cout << cellEnd - cellStart << pieceEnd - pieceStart << std::endl;
		}
	}