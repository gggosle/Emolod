#pragma once
#include "PotionInterface.h"
class APotion : public PotionInterface {
	void drink(Player* player) override {
		player->setAgility(player->getAgility() + 5);
		cout << "I`ve drunk agility potion" << endl;
	}
};

