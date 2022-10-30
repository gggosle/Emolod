#pragma once
#include "PotionInterface.h"
class ExpPotion : public PotionInterface {
	void drink(Player* player) override {
		player->setExperience(player->getExperience() + 100);
		cout << "I`ve drunk exp potion" << endl;
	}
};


