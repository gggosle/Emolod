#pragma once
#include "Player.h"
#include "Monster.h"
#include "Engine.h"
#include <vector>
#include "FunctionHelper.h"
#include "NameHelper.h"
#include <iostream>
#include "PotionInterface.h"
#include "HpPotion.h"
#include "PPotion.h"
#include "ExpPotion.h"
#include "EPotion.h"
#include "APotion.h"
#include <ctime>
using namespace std;

class Event {
private:
	int n = 0;
	


	//Monster* monster = NULL;
	Player* player = NULL;
	Engine* engine = NULL;
	vector <Shield*> shiel;
	vector <Weapon*> weap;
	vector <PotionInterface*> inventory;
public:
	Event(Player* player, Engine* engine) {
		this->player = player;
		this->engine = engine;
	}
	void potionShop() {
		if (this->player->getCash() >= 60) {
			int c = 0;
			cout << "You look in your wallet and see " << this->player->getCash() << " grivnas" << endl;
			inventory.clear();
			for (int i = 0; i < 5; i++) {
				int k = rand()%5;
				if (k == 0) {
					inventory.push_back(this->engine->aPotionGeneration());
				}
				else if (k == 1) {
					inventory.push_back(this->engine->ePotionGeneration());
				}
				else if (k == 2) {
					inventory.push_back(this->engine->pPotionGeneration());
				}
				else if (k == 3) {
					inventory.push_back(this->engine->expPotionGeneration());
				}
				else {
					inventory.push_back(this->engine->hpPotionGeneration());
				}
			}
			for (int i = 0; i < 5; i++) {
				cout << i + 1 << ". ";
				inventory[i]->showPotionData(inventory[i]->getName());
			}
			
			cout << "Input number of item you chose or other if you want to leave: " << endl;
			cin >> c;
			for (int i = 0; i < 5; i++) {
				if (c == i-1) {
					if (this->player->getCash() >= inventory[i]->getPrice()) {
						inventory[i]->drink(player);
					}
					else {
						cout << "Unfortunately, you don't have enough money for this item" << endl;
					}
				}
			}
			cout << "Good luck on your way, "  << this->player->getName() << endl;

		}
	}
	void shop() {
			cout << "You look in your wallet and see " << this->player->getCash() << " grivnas" << endl;
			shiel.clear();
			weap.clear();
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
			cout << "Input number of item you chose or other if you want to leave: ";
			cin >> n;
			
			if (n < 4 && n > 0) {
				if (shiel[n - 1]->getPrice() <= this->player->getCash()) {
					this->player->setCash(this->player->getCash() - shiel[n - 1]->getPrice());
					this->player->setShield(shiel[n - 1]);
				}
				else {
					cout << "Unfortunately, now you don't have enough money for this item " << endl;
				}
			}
			else if(n>=4 && n < 7) {
				if (weap[n - 4]->getPrice() <= this->player->getCash()) {
					this->player->setCash(this->player->getCash() - weap[n - 4]->getPrice());
					this->player->setWeapon(weap[n - 4]);
					player->getWeapon()->showWeaponData();
				}
				else {
					cout << "Unfortunately, now you don't have enough money for this item " << endl;
				}
			}
			else {
				cout << "Right now we have nothing else to offer you. See you next time" << endl;
			}

	}
	bool bumpIntoMonster() {
		Monster* monster = this->engine->monsterGeneration(this->player->getLevel());
		this->engine->fight(player, monster);
		return 0;
	}





};
