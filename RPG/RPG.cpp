#include <iostream>
#include <ctime>
#include <cmath>
#include <vector> 
#include "NameTrait.h" 
#include "Shield.h" 
#include "Characteristics.h"
#include "Weapon.h"
#include "FunctionHelper.h"
#include "Player.h"
#include "Monster.h"
#include "NameHelper.h"
#include "Engine.h"
#include "Event.h"
#include <fstream>
#include <conio.h>
<<<<<<< HEAD
=======

using namespace std;
class SaveLoad {
public:
	Player* load() {
		Player* player = NULL;
		ifstream load;
		load.open("emolod.txt");
		load.read((char*)&player, sizeof(Player));
		load.close();

		return player;
>>>>>>> 25b75d01ff6c8e7a8dfa5c3968e1e1e1a06bd34e

using namespace std;









class PotionInterface {
public:
	virtual void drink(Player* player) = 0;
};

class HpPotion : public PotionInterface {
	void drink(Player* player) override {
		player->setHp(player->getHp() + 50);
		cout << "I`ve drunk hp potion" << endl;
	}
};

class MpPotion : public PotionInterface {
	void drink(Player* player) override {
		player->setMp(player->getMp() + 10);
		cout << "I`ve drunk mp potion" << endl;
	}
};

class ExpPotion : public PotionInterface {
	void drink(Player* player) override {
		player->setExp(player->getExp() + 100);
		cout << "I`ve drunk exp potion" << endl;
	}
};

int addPotion(Player* player) {
	vector <PotionInterface*> inventory;

	for (int i = 0; i < 10; i++) {
		PotionInterface* pi = NULL;

		if (rand() % 3 == 1) {
			pi = new HpPotion();
		}
		else if (rand() % 3 == 2) {
			pi = new MpPotion();
		}
		else {
			pi = new ExpPotion();
		}

		inventory.push_back(pi);
	}


	for (int i = 0; i < inventory.size(); i++) {
		inventory[i]->drink(player);
	}

	return 1;

};


int main() {
	srand(time(NULL));
	Player* player = NULL;
	Engine* engine = new Engine(new FunctionHelper(), new NameHelper());
	SaveLoad* saveload = new SaveLoad();
	cout << "Continue?(Press 'c')" << endl;
	int key = _getch();
	if (key == 99) {
		player = saveload->load();
	}
	else {
		player = engine->playerGeneration();
<<<<<<< HEAD
		Weapon* fists = new Weapon("bare fists", 4, 0);
		player->setWeapon(fists);
		Shield* adrenaline = new Shield("adrenaline", 4, 0);
		player->setShield(adrenaline);

	}
	cout << endl;
	player->stats();
	cout << endl;
	cout << "To save your character's progress input 's'" << endl;
	cout << "To see your stats input 't'" << endl;
=======
		player->setWeapon(engine->weaponGeneration());
		player->setShield(engine->shieldGeneration());
	}
>>>>>>> 25b75d01ff6c8e7a8dfa5c3968e1e1e1a06bd34e
	
	Event* event = new Event(player, engine);
	int pos = 0;
	
	
	while (player->getLevel() < 10) {
<<<<<<< HEAD
		
		
			pos = 1 + rand() % 100;
			if (pos <= 5) {
				cout << endl;
				event->shop();
			}
			else if (pos > 5 && pos <= 45) {
				cout << endl;
				event->bumpIntoMonster();
			}
			else if (pos > 45 && pos <= 70) {
				cout << endl;
				player->setEnergy(1 + rand() % 5);

				cout << "Have some rest" << endl;
				player->setHealthMax(player->getHealthMax() + 1);
				cout << "Health: " << player->getHealthMax() << endl;
				
			}
		
		

=======
		pos = 1 + rand() % 100;
		if (pos <= 5) {
			event->shop();
		}
		else if (pos > 5 && pos <= 45) {
			event->bumpIntoMonster();
		}
		else if (pos > 45 && pos <= 70) {
			player->setEnergy(1 + rand() % 5);
		}
>>>>>>> 25b75d01ff6c8e7a8dfa5c3968e1e1e1a06bd34e
	}
	/*saveload->save(player);*/
	
}