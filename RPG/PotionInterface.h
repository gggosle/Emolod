#pragma once
#include "Player.h"
class PotionInterface {
private:
	
	int def = 0;
	int price = 0;
	
public:
	PotionInterface( int price, int def) {
		
		this->def = def;
		this->price = price;
	}
	int getPrice() {
		return this->price;
	}
	virtual void drink(Player* player) = 0;
	virtual string getName() = 0;

	void showPotionData(string name) {
		cout << name << ": " << this->def << " || " << this->price << " grivnas" << endl;
	}
};

