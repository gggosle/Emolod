#pragma once
#include "PotionInterface.h"
class ExpPotion : public PotionInterface {
private:
	string name = "experience";
public:
	ExpPotion(int price, int def) : PotionInterface(price, def) {
	}
	void drink(Player* player) override {
		player->setExperience(player->getExperience() + 100);
		cout << "I`ve drunk exp potion" << endl;
	}
	string getName() override {
		return this->name;
	}
};


