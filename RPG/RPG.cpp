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

	}
	void save(Player* player) {
		cout << "To save your character's progress press 's'" << endl;
		int key = _getch();
		if (key == 115) {
			ofstream save;
			save.open("emolod.txt");
			save.write((char*)&player, sizeof(Player));
			save.close();
		}
	}
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
		player->setWeapon(engine->weaponGeneration());
		player->setShield(engine->shieldGeneration());
	}
	
	Event* event = new Event(player, engine);
	int pos = 0;
	while (player->getLevel() < 10) {
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
	}
	saveload->save(player);

}

