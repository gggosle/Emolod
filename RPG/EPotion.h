#pragma once
#include "PotionInterface.h"
class EPotion : public PotionInterface {
	void drink(Player* player) override {
		player->setEndurance(player->getEndurance() + 5);
		cout << "I`ve drunk endurance potion" << endl;
	}
};

