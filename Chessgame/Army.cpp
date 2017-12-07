/*
	@author Antoine "Anthony" Sébert
	@creation_date 10/11/2017
	@description player army container
*/

#include "Army.h"

using namespace std;

// public
	Army::Army(unsigned int* newColor) : color(newColor) {
		alivePieces.push_back(make_shared<Rook>(color));
		alivePieces.push_back(make_shared<Knight>(color));
		alivePieces.push_back(make_shared<Bishop>(color));
		if (*color == 0) {
			// à vérifier
			alivePieces.push_back(make_shared<Queen>(color));
			alivePieces.push_back(make_shared<King>(color));
		}
		else {
			// à vérifier
			alivePieces.push_back(make_shared<King>(color));
			alivePieces.push_back(make_shared<Queen>(color));
		}
		alivePieces.push_back(make_shared<Bishop>(color));
		alivePieces.push_back(make_shared<Knight>(color));
		alivePieces.push_back(make_shared<Rook>(color));
		for (unsigned int i = 0; i < 8; ++i)
			alivePieces.push_back(make_shared<Pawn>(color));
	}
	Army::~Army() {}
	vector<shared_ptr<Piece>>* Army::getArmyContainer() {
		return &alivePieces;
	}
	unsigned int Army::getArmySize() {
		return (unsigned int)alivePieces.size();
	}
	void Army::displayArmy() {
		for (auto piece : alivePieces)
			cout << piece->getRepresentation();
		cout << endl;
		for (auto piece : deadPieces)
			cout << piece->getRepresentation();
		cout << endl;
	}
	shared_ptr<Piece> Army::operator[](unsigned int index) {
		return alivePieces.at(index);
	}
	vector<shared_ptr<Piece>>::iterator Army::getBegin() {
		return alivePieces.begin();
	}
	vector<shared_ptr<Piece>>::iterator Army::getEnd() {
		return alivePieces.end();
	}
// protected
// private
