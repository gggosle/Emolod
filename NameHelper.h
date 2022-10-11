#include <iostream>
using namespace std;

class NameHelper {
private:
	string monsterNames[10] = { "Bogeyman","Vampire","Zombie", "Hydra","Chimera","Yeti","Dragon","Basilisk","Werewolf", "Gorgon" };
	string shieldNames[5] = { "Viking Shield", "Bouche Shield","Buckler Shield","Heater Shield","Kite Shield" };
	string weaponNames[5] = { "Sword", "Dagger", "Pike", "Axe", "Spear" };
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

