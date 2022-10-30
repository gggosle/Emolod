#pragma once
#include "PotionInterface.h"


class HpPotion : public PotionInterface {
	void drink(Player* player) override {
		player->setHealthMax(player->getHealthMax() + 10);
		cout << "I`ve drunk health potion" << endl;
	}
};

