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
using namespace std;

int main() {
	int pos = 0;
	Engine* engine = new Engine(new FunctionHelper(), new NameHelper(), new Event());
	Player* player = engine->playerGeneration();

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
}


