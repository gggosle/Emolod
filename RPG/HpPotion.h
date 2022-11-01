#pragma once
#include "PotionInterface.h"


class HpPotion : public PotionInterface {
private:
	string name = "health";
public:
	HpPotion(int price, int def) : PotionInterface(price, def) {
	}
	void drink(Player* player) override {
		player->setHealthMax(player->getHealthMax() + 10);
		cout << "I`ve drunk health potion" << endl;
	}
	string getName() override {
		return this->name;
	}
};

