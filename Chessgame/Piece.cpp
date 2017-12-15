/**
	\author Antoine "Anthony" Sébert
	\date 04/11/2017
	\brief abstract class for the pieces
*/

#include "Piece.h"

using namespace std;

// public
	Piece::Piece() {}
	boardCoord Piece::getPosition() {
		return position;
	}
	void Piece::setPosition(boardCoord newPosition) {
		position = newPosition;
	}
// protected
	vector<boardCoord> const& Piece::linesPositions() const {
		vector<boardCoord> moves;
		// left - right
		for (unsigned int i = get<0>(position); 0 < i;)
			moves.push_back(make_tuple(--i, get<1>(position)));
		// right - left
		for (unsigned int i = get<0>(position); i < 7;)
			moves.push_back(make_tuple(++i, get<1>(position)));
		// bottom - top
		for (unsigned int i = get<1>(position); 0 < i;)
			moves.push_back(make_tuple(get<0>(position), --i));
		// top - bottom
		for (unsigned int i = get<1>(position); i < 7;)
			moves.push_back(make_tuple(get<0>(position), ++i));
		return moves;
	}