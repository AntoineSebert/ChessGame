/**
	@author Antoine "Anthony" Sébert
	@creation_date 06/11/2017
	@description player
*/

#include "Player.h"

using namespace std;

// public
	Player::Player(string playerName, unsigned int newColor, Interface* newGameInterface) : name(playerName), color(newColor), gameInterface(newGameInterface) {}
	Player::~Player() {}
	string Player::getName() { return name; }
	unsigned int Player::getColor() { return color; }
	void Player::initializeArmy(Board* gameBoard) {
		// only the player holds the pointer
		playerArmy = make_unique<Army>(&color);
		// if black player, the pawns are in row 1, otherwise in row 6
		unsigned int pawnRowNumber = (color == 0 ? 1 : 6);
		// if black player, the other pieces are in row 0, otherwise in row 7
		unsigned int bourgeoisieRowNumber = (color == 0 ? 0 : 7);
		// place pawns
		placePieces(
			pawnRowNumber,
			gameBoard->getBegin(pawnRowNumber), gameBoard->getEnd(pawnRowNumber),
			playerArmy->getBegin() + 8, playerArmy->getEnd()
		);
		// place other pieces
		placePieces(
			bourgeoisieRowNumber,
			gameBoard->getBegin(bourgeoisieRowNumber), gameBoard->getEnd(bourgeoisieRowNumber),
			playerArmy->getBegin(), playerArmy->getEnd() - 8
		);
	}
	tuple<boardCoord, boardCoord> Player::play(Board* gameBoard) {
		vector<string> labels;
		unsigned int choice;
		// select a piece, and select a move
		do {
			// select a piece
			labels = { "Chosse a piece to select" };
			for (shared_ptr<Piece> piece : *playerArmy->getArmyContainer())
				labels.push_back(
					(char)(get<0>(piece->getPosition()) + 65) + to_string(get<1>(piece->getPosition()))
				);
			selectPiece(gameInterface->numberChoice(&labels, (unsigned int)labels.size() - 1));

			// select a move, or deselect
			labels = { "Chosse a move or deselect piece" };
			possibleMoves(selectedPiece);
			// for
			labels.push_back("Deselect");
			choice = gameInterface->numberChoice(&labels, (unsigned int)labels.size() - 1);
		} while (choice < labels.size() - 2); // if choice is not 'deselect'
		// record start position
		boardCoord initialPosition = selectedPiece.lock()->getPosition();
		// record end position, and perform move
		boardCoord moveChoice = movePiece(choice);
		//vdeselect piece
		selectedPiece.reset();
		return forward_as_tuple(initialPosition, moveChoice);
	}
	void Player::selectPiece(unsigned int number) {
		selectedPiece = (*playerArmy)[number];
		cout << selectedPiece.lock()->getRepresentation() << endl;
		//
	}
	boardCoord Player::movePiece(unsigned int number) {
		//
		return boardCoord();
	}
// protected
// private
	void Player::placePieces(
		unsigned int rowNumber,
		boardRow::iterator cellStart, boardRow::iterator cellEnd,
		vector<shared_ptr<Piece>>::iterator pieceStart, vector<shared_ptr<Piece>>::iterator pieceEnd
	) {
		// check if iterators are correct
		if (cellEnd - cellStart == pieceEnd - pieceStart && cellStart < cellEnd && pieceStart < pieceEnd) {
			auto pieceIt = pieceStart;
			for (auto it = cellStart; it < cellEnd; ++it) {
				// assign positions to pieces
				(*pieceIt)->setPosition(forward_as_tuple(distance(cellStart, it), rowNumber));
				// assign pointers to pieces
				(*it)->setPiece(*pieceIt);
				// second limitating variable (ternary condition impossible because of 'break')
				if (pieceIt != pieceEnd)
					++pieceIt;
				else
					break;
			}
		}
		else {
			// throw error and information
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
		for (boardCoord move : piece.lock()->movement())
			cout << (char)(get<0>(move) + 65) << ':' << get<1>(move) << endl;
		return vector<unsigned int>();
	}
