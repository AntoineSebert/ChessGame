/*
	@author Antoine "Anthony" Sébert
	@creation_date 04/11/2017
	@description abstract class for the pieces
*/

#include "Piece.h"

Piece::Piece() {}

tuple<unsigned int, unsigned int> Piece::getPosition() {
	return position;
}

void Piece::setPosition(tuple<unsigned int, unsigned int> newPosition) {
	position = newPosition;
}
