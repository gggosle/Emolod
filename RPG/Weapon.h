#pragma once
#include "NameTrait.h"
#include <iostream>
#include "Id.h"
using namespace std;

class Weapon : public NameTrait, public Id {
	int damage = 0;
	int price = 0;
public:
	Weapon(string name, int damage, int price, int id) :NameTrait(name), Id(id) {
		this->damage = damage;
		this->price = price; 
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
		cout << this->name << " | damage value:  " << this->damage << " | price: " << this->price << endl;
	}
};

