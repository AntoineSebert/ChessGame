/*
	@author Antoine "Anthony" Sébert
	@creation_date 06/11/2017
	@description player
*/

#include "Player.h"

// public
	Player::Player(string playerName, unsigned int newColor) {
		name = playerName;
		color = newColor;
	}
	Player::~Player() {}
	string Player::getName() { return name; }
	unsigned int Player::getColor() { return color; }
	void Player::initializeArmy(Board* gameBoard) {
		playerArmy = make_unique<Army>(&color);
		if (color == 0) {
			placePieces(
				gameBoard->getBegin(1), gameBoard->getEnd(1),
				playerArmy->getBegin() + 8, playerArmy->getEnd()
			);
			placePieces(
				gameBoard->getBegin(0), gameBoard->getEnd(0),
				playerArmy->getBegin(), playerArmy->getEnd() - 8
			);
		}
		else {
			placePieces(
				gameBoard->getBegin(6), gameBoard->getEnd(6),
				playerArmy->getBegin() + 8, playerArmy->getEnd()
			);
			placePieces(
				gameBoard->getBegin(7), gameBoard->getEnd(7),
				playerArmy->getBegin(), playerArmy->getEnd() - 8
			);
		}
	}
	void Player::play() {

		selectPiece(3, 'A');
		/*
		do {
			//string input =
		} while ();
		*/
		movePiece(3, 'A');
	}
	void Player::selectPiece(unsigned int x, char y) {
		string test;
		cin >> test;
	}
	void Player::movePiece(unsigned int x, char y) {

	}
// protected
// private
	void Player::placePieces(
		array<shared_ptr<Cell>, 8>::iterator cellStart, array<shared_ptr<Cell>, 8>::iterator cellEnd,
		vector<shared_ptr<Piece>>::iterator pieceStart, vector<shared_ptr<Piece>>::iterator pieceEnd
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
			perror("The given intervals does not match or the iterators are unordered");
			cout << cellEnd - cellStart << ' ' << pieceEnd - pieceStart << endl;
			cout << *cellEnd << ':' << *cellStart << ' ' << *pieceEnd << ':' << *pieceStart << endl;
		}
	}