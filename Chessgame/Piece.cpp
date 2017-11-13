/*
	@author Antoine "Anthony" Sébert
	@creation_date 04/11/2017
	@description abstract class for the pieces
*/

#include "Piece.h"

Piece::Piece() : representation('*') {}

char Piece::getRepresentation() {
	return representation;
}
