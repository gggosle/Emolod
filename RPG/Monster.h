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


	int getDefense() {
		return defense = this->fH->getCharacteristic(health, level, 10) / (1 + rand() % 10);

	}
};
