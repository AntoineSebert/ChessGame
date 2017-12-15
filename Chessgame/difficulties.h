/*!
	\author		Antoine "Anthony" Sébert
	\date		05/11/2017
	\brief		difficulties
	\details
		If there is no entity player, the difficulty is automatically set to NONE.

		RANDOM : the computer will choose a random move each turn.

		EASY : easy difficulty.

		MEDIUM : medium difficulty.

		HARD : hard difficulty.
*/

#pragma once

enum difficulties {
	RANDOM,
	EASY,
	MEDIUM,
	HARD,
	NONE
};