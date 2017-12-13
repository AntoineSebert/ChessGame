/*
	@author Antoine "Anthony" Sébert
	@creation_date 06/11/2017
	@description board element container
*/

#include "Cell.h"

using namespace std;

// public
	Cell::Cell(unsigned int newColor) : color(newColor) {}
	Cell::~Cell() {}
	unsigned int Cell::getColor() {
		return color;
	}
	void Cell::displayContent() {
		cout << (isUninitialized(content) ? '*' : content.lock()->getRepresentation());
	}
	void Cell::setPiece(weak_ptr<Piece> newPiece) {
		content = newPiece;
	}
	void Cell::removePiece() {
		content.reset();
	}
// protected
// private
	template<typename T>
	inline bool Cell::isUninitialized(weak_ptr<T> const & weak) {
		using wt = weak_ptr<T>;
		return !weak.owner_before(wt{}) && !wt{}.owner_before(weak);
	}