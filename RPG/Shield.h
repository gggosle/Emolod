#pragma once
#include <iostream>
#include "NameTrait.h"
using namespace std;


class Shield : public NameTrait {
private:
	int defense = 0;
	int price = 0;
public:
	Shield(string name, int shield, int price) : NameTrait(name) {
		this->defense = shield;
	}
	void setPrice(int price) {
		this->price = price;
	}
	int getPrice() {
		return price;
	}
	void setDefense(int shield) {
		this->defense = shield;
	}
	int getDefense() {
		return defense;
	}
	void showShieldData() {
		cout << this->name << " defense value:  " << this->defense << " ------  price: " << this->price << endl;
	}
};

