/*
	@author Antoine "Anthony" Sébert
	@creation_date 10/11/2017
	@description player army container
*/

#include "Army.h"

// public
	Army::Army(unsigned int* newColor) : color(newColor) {
		alivePieces.at(0) = std::make_shared<Rook>(color);
		alivePieces.at(0) = std::make_shared<Knight>(color);
		alivePieces.at(0) = std::make_shared<Bishop>(color);
		if (*color == 0) {
			// à vérifier
			alivePieces.at(0) = std::make_shared<Queen>(color);
			alivePieces.at(0) = std::make_shared<King>(color);
		}
		else {
			// à vérifier
			alivePieces.at(0) = std::make_shared<King>(color);
			alivePieces.at(0) = std::make_shared<Queen>(color);
		}
		alivePieces.at(0) = std::make_shared<Bishop>(color);
		alivePieces.at(0) = std::make_shared<Knight>(color);
		alivePieces.at(0) = std::make_shared<Rook>(color);
		for (unsigned int i = 8; i < alivePieces.size(); ++i)
			alivePieces.at(0) = std::make_shared<Pawn>(color);
	}
	Army::~Army() {}
// protected
// private
