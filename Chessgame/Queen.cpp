/**
	\author Antoine "Anthony" Sébert
	\date 14/11/2017
	\brief queen class
*/

#include "Queen.h"

using namespace std;

// public
	Queen::Queen(unsigned int* newColor) {
		color = newColor;
		representation = 'Q';
	}
	Queen::~Queen() {}
	char Queen::getRepresentation() {
		return representation;
	}
	vector<boardCoord> const Queen::movement() const {
		vector<boardCoord> moves, temp = linesPositions();
		moves.reserve(moves.size() + temp.size());
		std::move(temp.begin(), temp.end(), std::back_inserter(moves));

		unsigned int i, ii;
		// bottom left
			i = (get<0>(position) < get<1>(position) ? get<0>(position) : get<1>(position));
			ii = (get<0>(position) >= get<1>(position) ? get<0>(position) : get<1>(position));
			for (; 0 < i;)
				moves.push_back((get<0>(position) < get<1>(position) ? make_tuple(--i, --ii) : make_tuple(--ii, --i)));
		// bottom right
		// top left
		// top right
			i = (get<0>(position) < get<1>(position) ? get<1>(position) : get<0>(position));
			ii = (get<0>(position) >= get<1>(position) ? get<1>(position) : get<0>(position));
			for (; i < 7;)
				moves.push_back((get<0>(position) < get<1>(position) ? make_tuple(++ii, ++i) : make_tuple(++i, ++ii)));
		return moves;
	}