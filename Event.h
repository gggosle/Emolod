#pragma once
#include "Player.h"
#include "Monster.h"
#include "Engine.h"
#include <vector>
class Event {
private:
	int n = 0;
	Monster* monster = NULL;
	Player* player = NULL;
	Engine* engine = new Engine(new FunctionHelper(), new NameHelper());
	vector <Shield*> shiel;
	vector <Weapon*> weap;
public:
	Event(Player* player) {
		this->player = player;
	}

	void shop() {
		if (this->player->getCash() >= 60) {
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
			cout << "Number of item you chose: ";
			cin >> n;

			if (shiel[n - 1]->getPrice() <= this->player->getCash()) {
				this->player->setCash(this->player->getCash() - shiel[n - 1]->getPrice());
				this->player->setShield(shiel[n - 1]);
			}
			if (weap[n - 4]->getPrice() <= this->player->getCash()) {
				this->player->setCash(this->player->getCash() - weap[n - 4]->getPrice());
				this->player->setShield(shiel[n - 4]);
			}

		}
		else {
			cout << "Right now we have nothing to offer you. See you next time" << endl;
		}



	}
	void bumpIntoMonster() {
		Monster* monster = this->engine->monsterGeneration(this->player->getLevel());
	}
	void improvement() {
		if (this->player->levelUp()) {
			cout << "Congrats! You've reached new level!" << endl;
			cout << "Your power now: " << this->player->getPower() << endl;
			cout << "Your agility now: " << this->player->getAgility() << endl;
			cout << "Your endurance now: " << this->player->getEndurance() << endl;
		}
		if (this->player->experienceUp(this->monster->getPlayerExperience())) {
			cout << "Your experience: +" << this->monster->getPlayerExperience() << endl;
		}
		if (this->player->cashUp(this->monster->getCash())) {
			cout << "Your cash: +" << this->monster->getCash();
		}

	}
};

