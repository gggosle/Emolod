#pragma once
#include "Player.h"
#include "Monster.h"
#include "Engine.h"
#include <vector>
#include "FunctionHelper.h"
#include "NameHelper.h"
#include <iostream>
using namespace std;

class Event {
private:
	int n = 0;
<<<<<<< HEAD

=======
	
>>>>>>> 25b75d01ff6c8e7a8dfa5c3968e1e1e1a06bd34e
	//Monster* monster = NULL;
	Player* player = NULL;
	Engine* engine = NULL;
	vector <Shield*> shiel;
	vector <Weapon*> weap;
public:
	Event(Player* player, Engine* engine) {
		this->player = player;
		this->engine = engine;
	}
	void potionShop() {
		if (this->player->getCash() >= 60) {
			cout << "You look in your wallet and see " << this->player->getCash() << " hryvnias" << endl;
		}
	}
	void shop() {
		if (this->player->getCash() >= 60) {
			cout << "You look in your wallet and see " << this->player->getCash() << " hryvnias" << endl;
			while (shiel.size() < 3) {
				shiel.push_back(this->engine->shieldGeneration());
			}
			while (weap.size() < 3) {
				weap.push_back(this->engine->weaponGeneration());
			}
			for (int i = 0; i < 3; i++) {
				cout << i + 1 << ". ";
				shiel[i]->showShieldData();
			}
			for (int i = 0; i < 3; i++) {
				cout << i + 4 << ". ";
				weap[i]->showWeaponData();
			}
			cout << "Input number of item you chose or leave('9'): ";
			cin >> n;
			if (n == 9) {
				cout << "Right now we have nothing else to offer you. See you next time" << endl;
			}
			else if (n < 4) {
				if (shiel[n - 1]->getPrice() <= this->player->getCash()) {
					this->player->setCash(this->player->getCash() - shiel[n - 1]->getPrice());
					this->player->setShield(shiel[n - 1]);
				}
				else {
					cout << "Unfortunately, now you don't have enough money for this item " << endl;
				}
			}
			else {
				if (weap[n - 4]->getPrice() <= this->player->getCash()) {
					this->player->setCash(this->player->getCash() - weap[n - 4]->getPrice());
					this->player->setWeapon(weap[n - 4]);
					player->getWeapon()->showWeaponData();
				}
				else {
					cout << "Unfortunately, now you don't have enough money for this item " << endl;
				}
			}
			
		}
		else {
			cout << "Right now we have nothing to offer you. See you next time" << endl;
		}



	}
	bool bumpIntoMonster() {
		Monster* monster = this->engine->monsterGeneration(this->player->getLevel());
<<<<<<< HEAD
		this->engine->fight(player, monster);
		return 0;
	}
	
		
		
=======
		this->engine->fight(this->player, monster);
		return 0;
	}
	void improvement(Monster* monster) {
		if (this->player->levelUp()) {
			cout << "Congrats! You've reached new level!" << endl;
			cout << "Your power now: " << this->player->getPower() << endl;
			cout << "Your agility now: " << this->player->getAgility() << endl;
			cout << "Your endurance now: " << this->player->getEndurance() << endl;
		}
		if (this->player->experienceUp(monster->getPlayerExperience())) {
			cout << "Your experience: +" << monster->getPlayerExperience() << endl;
		}
		if (this->player->cashUp(monster->getCash())) {
			cout << "Your cash: +" << monster->getCash();
		}
>>>>>>> 25b75d01ff6c8e7a8dfa5c3968e1e1e1a06bd34e

	
};
