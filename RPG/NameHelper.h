#pragma once
#include <iostream>
#include <map>


using namespace std;

class NameHelper {
private:
	map<string, int>MonsterName = {};
	map<string, int>ShieldName = {};
	map<string, int>WeaponName = {};
	string monsterNames[10] = { "Russian baby","Zombie","Skeleton","Yeti","Dragon","Gorgon","Vampire" ,"Hydra","Werewolf","Basilisk"  };
	string shieldNames[5] = { "Blindfold", "Garlic","Magic","Silver","Gasmask" };
	string weaponNames[5] = { "AK-74","Chainsaw",  "Bow", "Axe", "Diamond sword" };
public:
	
	int getMonsterId(string name) {
		int j = 0;
		for (string name : monsterNames) {
			this->MonsterName.insert(pair<string, int>(monsterNames[j], j+1));
			j += 1;
		}	
		return this->MonsterName[name];
	}
	int getShieldId(string name) {
		int j = 0;
		for (string name : shieldNames) {
			this->ShieldName.insert(pair<string, int>(shieldNames[j], j + 6));
			j += 1;
		}
		return this->ShieldName[name];
	}
	int getWeaponId(string name) {
		int j = 0;
		for (string name : weaponNames) {
			this->WeaponName.insert(pair<string, int>(weaponNames[j], j + 1));
			j += 1;
		}
		return this->WeaponName[name];
	}

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
