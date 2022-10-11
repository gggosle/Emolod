#pragma once
#include "Characteristics.h"
using namespace std;
class Monster : public Characteristics {

private:
	int damage = 0;
	int shield = 0;
	int playerExperience = 0;
	int cash = 0;
public:
	Monster(string name, int health, int energy, int playerExperience, int level) : Characteristics(health, energy, name, level) {
		this->playerExperience = playerExperience;

		this->cash = 100 * this->level + rand() % 200;
	}
	void setCash(int cash) {
		this->cash = cash;
	}
	int getCash() {
		return cash;
	}
	void setDamage(int damage) {
		this->damage = damage;
	}
	void setShield(int shield) {
		this->shield = shield;
	}
	
	void setPlayerExperience(int playerExperience) {
		this->playerExperience = playerExperience;
	}
	int getPlayerExperience() {
		return playerExperience;
	}
	int generateDamage() {
		return this->fH->getCharacteristic(health, level, 10) / (rand() % 10);
	}
	
	int generateShield() {
		int c = 22;
		c += level * 4;
		int shieldChance = (this->fH->randomRes(0, c) * 100) / c;
		if (1 + rand() % (10 / shieldChance) == 1 + rand() % (10 / shieldChance)) {
			return this->fH->getCharacteristic(health, level, 10) / (rand() % 10);
		}
		else {
			return shield;
		}
	}
};

