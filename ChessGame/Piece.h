#pragma once

#include<memory>

/*
	@author Antoine "Anthony" Sébert
	@creation_date 04/11/2017
	@description abstract class for the pieces
*/

class Piece {
	// attributes
		// public
		// protected
		private:
			//std::weak_ptr<Player> owner;
			std::weak_ptr<unsigned int> color;
			char representation;

	// members
		public:
			Piece();
			~Piece();
			std::array<Cell> myfunc() {

			}
		// protected
		// private
};