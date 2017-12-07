/*
	@author Antoine "Anthony" Sébert
	@creation_date 04/11/2017
	@description abstract class for the pieces
*/

#include "Piece.h"

using namespace std;

Piece::Piece() {}

// public
	tuple<unsigned int, unsigned int> Piece::getPosition() {
		return position;
	}
	void Piece::setPosition(tuple<unsigned int, unsigned int> newPosition) {
		position = newPosition;
	}
// protected
	vector<tuple<unsigned int, unsigned int>> const& Piece::linesPositions() const {
		vector<tuple<unsigned int, unsigned int>> moves;
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