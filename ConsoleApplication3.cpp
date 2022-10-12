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
	Monster* load() {
		Player* player = NULL;

		load.open("C:\Users\gakho\Desktop\New folder\Emolod\emolod.txt");
		load.read((char*)&player, sizeof(Player));
		load.close();
	}
	void save() {
		cout << "To save your character's progress press 's'" << endl;
		int key = _getch();
		if (key == 115) {
			ofstream save;
			save.open("C:\Users\gakho\Desktop\New folder\Emolod\emolod.txt");
			save.write((char*)&player, sizeof(Player));
			save.close;
		}
	}
};
int main() {
	Player* player = NULL;
	Engine* engine = new Engine(new FunctionHelper(), new NameHelper(), new Event());
	SaveLoad* saveload = new SaveLoad();
	cout << "Continue?(Press 'c')" << endl;
	int key = _getch();
	if (key == 99) {
		player = saveload->load();
	}
	else{
		player = engine->playerGeneration();
	}
	int pos = 0;
	while (player->getLevel < 10) {
		pos = 1 + rand() % 100;
		if (pos <= 5) {
			event->shop();
		}
		else if (pos > 5 && pos <= 45) {
			engine->fight();
		}
		else if (pos > 45 && pos <= 70) {
			player->setEnergy(1 + rand() % 5);
		}
	}
	saveload->save(player);
	
}


