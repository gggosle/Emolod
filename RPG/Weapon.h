#pragma once
#include "NameTrait.h"
#include <iostream>

class Weapon : public NameTrait {
	int damage = 0;
	int price = 0;
public:
	Weapon(string name, int damage, int price) :NameTrait(name) {
		this->damage = damage;
	}
	void setPrice(int price) {
		this->price = price;
	}
	int getPrice() {
		return price;
	}
	void setDamage(int damage) {
		this->damage = damage;
	}
	int getDamage() {
		return damage;
	}
	void showWeaponData() {
		cout << this->name << " defense value:  " << this->damage << " ------  price: " << this->price << endl;
	}
};

