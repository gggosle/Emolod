#pragma once
#include "Characteristics.h"
#include <iostream>
#include "Shield.h"
#include "Weapon.h"
using namespace std;

class Player : public Characteristics {
private:

	int power = 0;
	int c = 22;
	int agility = 0;
	int endurance = 0;
	int experience = 0;
	int experienceMax = 0;
	int playerDamage = 0;
	int playerShield = 0;
	int cash = 0;
	Shield* shield = NULL;
	Weapon* weapon = NULL;

public:
	Player(int health, int energy, int level, int power, int agility, int endurance, string name, int cash) :Characteristics(health, energy, name, level)
	{
		this->cash = cash;
		this->power = power;
		this->agility = agility;
		this->endurance = endurance;
		this->experience = 0;
		this->level = level;
		this->experienceMax = 1000 * this->level;

	}

	int levelUp() {
		this->level += 1;
		this->agility += rand() % 5;
		this->endurance = rand() % 5;
		this->power = rand() % 5;
		this->health = this->healthMax;
		this->energy = this->energyMax;
		this->c += 4;

		return 1;
	}
	int getLevel() {
		return this->level;
	}
	void setCash(int cash) {
		this->cash = cash;
	}
	int getCash() {
		return cash;
	}

	int healthRegeneration() {
		return this->health = this->healthMax;
	}

	void setShield(Shield* shield) {
		this->shield = shield;
	}

	Shield* getShield() {
		return this->shield;
	}

	void setWeapon(Weapon* weapon) {
		this->weapon = weapon;
	}

	Weapon* getWeapon() {
		return this->weapon;
	}

	void setPower(int power) {
		this->power = power;
	}
	int getPower() {
		return power;
	}void setAgility(int agility) {
		this->agility = agility;
	}int getAgility() {
		return agility;
	}void setEndurance(int endurance) {
		this->endurance = endurance;
	}int getEndurance() {
		return endurance;
	}
	int cashUp(int cash) {
		this->cash += cash;
	}
	void setExperience(int experience) {
		if (this->experienceUp(experience) > this->experienceMax) {
			this->experience = this->experienceUp(experience) - this->experienceMax;
			this->levelUp();
		}
		else {
			this->experienceUp(experience);
		}
	}
	int experienceUp(int experience) {
		this->experience += experience;

		return this->experience;
	}
	int getExperience() {
		return experience;
	}

	int generateDamage(int damage) {
		int playerDamage = (((damage + power) - 3) * this->fH->getCharacteristic(health, level, 10)) / this->c;
		int critical = this->fH->getCharacteristic(health, level, 10);
		int percentage = 4;
		for (int i = 0; i < level; i++) {
			percentage += 4;
		}
		int criticalChance = agility * 100 / percentage;

		int divizion = 0;
		if (criticalChance != 0) {
			if ((10 / criticalChance) == 0) {
				divizion = 1;
			}
			else {
				divizion = (10 / criticalChance);
			}

			if (1 + rand() % (10 / criticalChance) == 1 + rand() % (10 / criticalChance)) {
				return playerDamage = critical;
			}
		}

		return playerDamage;
	}

	int generateShield(int defense) {

		int defenseChance = (((defense + endurance) - 3) * 100) / this->c;
		int divizion = 0;
		if ((10 / defenseChance) == 0) {
			divizion = 1;
		}
		else {
			divizion = (10 / defenseChance);
		}
		if (1 + rand() % divizion == 1 + rand() % divizion) {
			return (((defense + endurance) - 3) * this->fH->getCharacteristic(health, level, 10)) / this->c;
		}
		else {
			return playerShield;
		}


	}

};

