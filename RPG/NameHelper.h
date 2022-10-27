#pragma once
#include <iostream>
using namespace std;

class NameHelper {
private:
	string monsterNames[10] = { "Russian baby","Vampire","Zombie", "Hydra","Chimera","Yeti","Dragon","Basilisk","Werewolf", "Gorgon" };
	string shieldNames[5] = { "Stone", "Wood","Magic","Diamond","Water" };
	string weaponNames[5] = { "Sword", "Stone", "Bow", "Axe", "Spear" };
public:
	string getMonsterName() {
		return this->monsterNames[rand() % 10];
	}
	string getShieldName() {
		return this->shieldNames[rand() % 5];
	}
	string getWeaponName() {
		return this->weaponNames[rand() % 5];
	}
};
