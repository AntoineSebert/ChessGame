/*
	@author Antoine "Anthony" Sébert
	@creation_date 04/11/2017
	@description abstract class for the pieces
*/

#include "Piece.h"

Piece::Piece(unsigned int newPosition, unsigned int* newColor) : representation('*'), color(newColor), position(newPosition) {}
