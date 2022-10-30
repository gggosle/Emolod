#pragma once
#include "Characteristics.h"
using namespace std;
class Monster : public Characteristics {

private:
	int damage = 0;

	int playerExperience = 0;
	int cash = 0;
	int defense = 0;
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
	
	int getLevel() {
		return this->level;
	}

	void setPlayerExperience(int playerExperience) {
		this->playerExperience = playerExperience;
	}
	int getPlayerExperience() {
		return playerExperience;
	}
	int getDamage() {
		int r = 22;
		for (int i = 0; i < level - 1; i++) {
			r += 4;
		}
		int min = 4;
		int max = 7;
		min = this->fH->getCharacteristic(min, level - 2, rand() % 5);
		max = this->fH->getCharacteristic(max, level - 2, rand() % 5 + rand() % 2 + 1);
		return damage = this->fH->randomRes(min, max)*this->fH->getCharacteristic(health, level, 10) / r;
	}

<<<<<<< HEAD
	int getDefense() {
		return defense = this->fH->getCharacteristic(health, level, 10) / (1 + rand() % 10);
=======
	int generateShield() {
		int c = 22;
		c += level * 4;
		int shieldChance = (this->fH->randomRes(0, c) * 100) / c;
		int divizion = 0;
		if ((10 / shieldChance) == 0) {
			divizion = 1;
		}
		else {
			divizion = (10 / shieldChance);
		}

		if (1 + rand() % divizion == 1 + rand() % divizion) {
			return this->fH->getCharacteristic(health, level, 10) / (1 + rand() % 10);
		}
		else {
			return shield;
		}
>>>>>>> 25b75d01ff6c8e7a8dfa5c3968e1e1e1a06bd34e
	}
};
