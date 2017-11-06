#pragma once

#include "Singleton.h"

/*
	@author Antoine "Anthony" S�bert
	@creation_date 06/11/2017
	@description player
*/


class Player : public Singleton<Player> {
	friend class Singleton<Player>;
	private:
	Player();
	~Player();
};

