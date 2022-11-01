#pragma once
#include "PotionInterface.h"
class EPotion : public PotionInterface {
private:
	string name = "endurance";
public:
	EPotion(int price, int def) : PotionInterface(price, def) {
	}
	void drink(Player* player) override {
		player->setEndurance(player->getEndurance() + 5);
		cout << "I`ve drunk endurance potion" << endl;
	}
	string getName() override {
		return this->name;
	}
};

