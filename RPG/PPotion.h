#pragma once
#include "PotionInterface.h"

class PPotion : public PotionInterface {
private:
	string name = "power";
public:
	PPotion( int price, int def) : PotionInterface( price, def) {

	}
	void drink(Player* player) override {
		player->setPower(player->getPower() + 5);
		cout << "I`ve drunk power potion" << endl;
	}
	string getName() override {
		return this->name;
	}
};

