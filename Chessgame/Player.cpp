/*
	@author Antoine "Anthony" Sébert
	@creation_date 06/11/2017
	@description player
*/

#include "Player.h"

// public
	Player::Player(string playerName, unsigned int newColor, Interface* newGameInterface) : name(playerName), color(newColor), gameInterface(newGameInterface) {}
	Player::~Player() {}
	string Player::getName() { return name; }
	unsigned int Player::getColor() { return color; }
	void Player::initializeArmy(Board* gameBoard) {
		playerArmy = make_unique<Army>(&color);
		unsigned int pawnRowNumber = (color == 0 ? 1 : 6);
		unsigned int bourgeoisieRowNumber = (color == 0 ? 0 : 7);
		placePieces(
			pawnRowNumber,
			gameBoard->getBegin(pawnRowNumber), gameBoard->getEnd(pawnRowNumber),
			playerArmy->getBegin() + 8, playerArmy->getEnd()
		);
		placePieces(
			bourgeoisieRowNumber,
			gameBoard->getBegin(bourgeoisieRowNumber), gameBoard->getEnd(bourgeoisieRowNumber),
			playerArmy->getBegin(), playerArmy->getEnd() - 8
		);
	}
	void Player::play(Board* gameBoard) {
		vector<string> labels;
		unsigned int moveChoice;
		do {
			labels = { "Chosse a piece to select" };
			for (shared_ptr<Piece> piece : *playerArmy->getArmyContainer())
				labels.push_back(
					(char)(get<0>(piece->getPosition()) + 65) + to_string(get<1>(piece->getPosition()))
				);
			selectPiece(gameInterface->numberChoice(&labels, (unsigned int)labels.size() - 1));
			labels = { "Chosse a move or deselect piece" };
			possibleMoves(selectedPiece);
			// for
			labels.push_back("Deselect");
			moveChoice = gameInterface->numberChoice(&labels, (unsigned int)labels.size() - 1);
		} while (moveChoice < labels.size() - 2);
		movePiece(moveChoice);
		selectedPiece.reset();
	}
	void Player::selectPiece(unsigned int number) {
		selectedPiece = (*playerArmy)[number];
		cout << selectedPiece._Get()->getRepresentation() << endl;
	}
	void Player::movePiece(unsigned int number) {

	}
// protected
// private
	void Player::placePieces(
		unsigned int rowNumber,
		array<shared_ptr<Cell>, 8>::iterator cellStart, array<shared_ptr<Cell>, 8>::iterator cellEnd,
		vector<shared_ptr<Piece>>::iterator pieceStart, vector<shared_ptr<Piece>>::iterator pieceEnd
	) {
		if (cellEnd - cellStart == pieceEnd - pieceStart && cellStart < cellEnd && pieceStart < pieceEnd) {
			auto pieceIt = pieceStart;
			for (auto it = cellStart; it < cellEnd; ++it) {
				(*pieceIt)->setPosition(forward_as_tuple(distance(cellStart, it), rowNumber));
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
	vector<unsigned int> Player::possibleMoves(weak_ptr<Piece> piece) {
		/*

		switch (typeid(piece).name()) {

		}
		*/
		//for
		for (tuple<unsigned int, unsigned int> move : piece._Get()->movement())
			cout << (char)(get<0>(move) + 65) << ':' << get<1>(move) << endl;
		return vector<unsigned int>();
	}
