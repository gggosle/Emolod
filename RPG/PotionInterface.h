#pragma once
#include "Player.h"
class PotionInterface {
public:
	virtual void drink(Player* player) = 0;
};

