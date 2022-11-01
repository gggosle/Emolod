#pragma once
#include "PotionInterface.h"
class APotion : public PotionInterface {
private:
	string name = "agility";
public:
	APotion(int price, int def) : PotionInterface(price, def) {
	}
	void drink(Player* player) override {
		player->setAgility(player->getAgility() + 5);
		cout << "I`ve drunk agility potion" << endl;
	}
	string getName() override {
		return this->name;
	}
};

