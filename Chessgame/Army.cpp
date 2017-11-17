/*
	@author Antoine "Anthony" Sébert
	@creation_date 10/11/2017
	@description player army container
*/

#include "Army.h"

// public
	Army::Army(unsigned int* newColor) : color(newColor) {
		alivePieces.push_back(std::make_shared<Rook>(color));
		alivePieces.push_back(std::make_shared<Knight>(color));
		alivePieces.push_back(std::make_shared<Bishop>(color));
		if (*color == 0) {
			// à vérifier
			alivePieces.push_back(std::make_shared<Queen>(color));
			alivePieces.push_back(std::make_shared<King>(color));
		}
		else {
			// à vérifier
			alivePieces.push_back(std::make_shared<King>(color));
			alivePieces.push_back(std::make_shared<Queen>(color));
		}
		alivePieces.push_back(std::make_shared<Bishop>(color));
		alivePieces.push_back(std::make_shared<Knight>(color));
		alivePieces.push_back(std::make_shared<Rook>(color));
		for (unsigned int i = 0; i < 8; ++i)
			alivePieces.push_back(std::make_shared<Pawn>(color));
	}
	Army::~Army() {}
	std::vector<std::shared_ptr<Piece>>* Army::getArmyContainer() {
		return &alivePieces;
	}
	unsigned int Army::getArmySize() {
		return (unsigned int)alivePieces.size();
	}
	void Army::displayArmy() {
		for (std::shared_ptr<Piece> piece : alivePieces)
			std::cout << piece.get()->getRepresentation();
		std::cout << std::endl;
		for (std::shared_ptr<Piece> piece : deadPieces)
			std::cout << piece.get()->getRepresentation();
		std::cout << std::endl;
	}
	std::shared_ptr<Piece> Army::operator[](unsigned int index) {
		return alivePieces.at(index);
	}
	std::vector<std::shared_ptr<Piece>>::iterator Army::getBegin() {
		return alivePieces.begin();
	}
	std::vector<std::shared_ptr<Piece>>::iterator Army::getEnd() {
		return alivePieces.end();
	}
// protected
// private
