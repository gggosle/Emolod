#pragma once
#include "NameTrait.h"
#include "FunctionHelper.h"
#include <iostream>
using namespace std;
class Characteristics : public NameTrait
{

protected:
	int health = 0;
	int healthMax = 0;
	int energy = 0;
	int energyMax = 0;
	int level = 0;
	FunctionHelper* fH = NULL;

public:
	Characteristics(int health, int energy, string name, int level) : NameTrait(name)
	{
		this->healthMax = health;
		this->health = health;
		this->energy = energy;
		this->energyMax = energy;
		this->level = level;
		this->fH = new FunctionHelper();
	}

	void setHealth(int health) {
		this->health = health;
	}
	int getHealth() {
		return health;
	}
	void setHealthMax(int healthMax) {
		this->healthMax = healthMax;
	}
	int getHealthMax() {
		return this->healthMax;
	}
	void setEnergy(int energy) {
		if (energy > this->energyMax) {
			this->energy = this->energyMax;
		}
		else {
			this->energy = energy;
		}
	}
	int getEnergy() {
		return energy;
	}void setName(int name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
	void setLevel(int level) {
		this->level = level;
	}
	int getLevel() {
		return level;
	}

};


