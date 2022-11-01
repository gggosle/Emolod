#pragma once
#include <iostream>


using namespace std;

class NameHelper {
private:
	
	string monsterNames[10] = { "Russian baby","Vampire","Zombie", "Hydra","Dragon","Yeti","Dragon","Basilisk","Werewolf", "Gorgon" };
	string shieldNames[5] = { "Blindfold", "Garlic","Magic","Silver","Gasmask" };
	string weaponNames[5] = { "Ñhainsaw", "AK-74", "Bow", "Axe", "Diamond sword" };
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
