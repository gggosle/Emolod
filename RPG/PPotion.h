#pragma once
#include "PotionInterface.h"

class PPotion : public PotionInterface {
	void drink(Player* player) override {
		player->setPower(player->getPower() + 5);
		cout << "I`ve drunk power potion" << endl;
	}
};

