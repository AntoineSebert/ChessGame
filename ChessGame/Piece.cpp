#include "Piece.h"

/*
	@author Antoine "Anthony" Sébert
	@creation_date 04/11/2017
	@description abstract class for the pieces
*/

Piece::Piece(std::weak_ptr<Player> newOwner) : owner(newOwner) {}

char Piece::getRepresentation() {
	return representation;
}
