#pragma once
#include "Monster.h"
#include "Player.h"
#include "NameHelper.h"
#include "SaveLoad.h"
//#include "Event.h"

#include <ctime>
#include "FunctionHelper.h"
#include "SkillInterface.h"
#include "MSkillInterface.h"
#include "Block.h"
#include "Attack.h"
#include "CriticalAttack.h"
#include "MBlock.h"
#include "MAttack.h"
#include <iostream>
using namespace std;

class Engine {
private:
	Monster* monster = NULL;
	Player* player = NULL;
	FunctionHelper* fH = NULL;
	NameHelper* nH = NULL;
	SaveLoad* saveL = NULL;
	SkillInterface* skill = NULL;
	MSkillInterface* mskill = NULL;
	bool defenseChance() {
		int defenseChance = ((((this->player->getShield()->getDefense() + this->player->getEndurance()) - 3) + 1) * 100) / this->player->getC();
		if (1 + rand() % defenseChance == 1 + rand() % defenseChance) {
			return 1;
		}
		return 0;
	}
	bool monsterDefenseChance() {
		int c = 22;
		c += this->monster->getLevel() * 4;
		int shieldChance = (this->fH->randomRes(1, c) * 100) / c;
		if (1 + rand() % shieldChance == 1 + rand() % shieldChance) {
			return 1;
		}
	}
	bool criticalChance() {
		int percentage = 4;
		for (int i = 0; i < this->player->getLevel(); i++) {
			percentage += 4;
		}
		int criticalChance = this->player->getAgility() * 100 / percentage;
		if (criticalChance != 0) {

			if (1 + rand() % (10 / criticalChance) == 1 + rand() % (10 / criticalChance)) {
				return 1;
			}
		}
	}
	int monsterTurn(bool miss) {
		int gap = 0;
		int f = 0;

		bool mb = 0;
		int chance = rand() % 3;
		if (miss == 1) {
			cout << this->player->getName() << "'s block" << endl;
			return 0;
		}
		if (monsterDefenseChance() == 1) {
			mb = 1;
		}
		if (monsterDefenseChance() == 1 && chance == 0) {
			mskill = new MBlock();
			this->monster->setHealth(mskill->use(this->monster));
			f = this->monster->getHealth();

		}
		else {
			mskill = new MAttack();
			gap = this->mskill->use(this->monster);
			f = this->player->getHealth() - gap;
		}




		if (f < this->player->getHealth()) {
			(f < 0) ? player->setHealth(0) : this->player->setHealth(f);
			cout << "-" << gap << endl << "Your health: " << this->player->getHealth() << endl;

		}





		return mb;
	}
	int playerTurn(bool miss) {
		int f = 0;
		char action = 0;
		int gap = 0;
		bool cc = 0;
		bool dc = 0;
		bool pc = 0;

		if (miss == 1) {
			cout << this->monster->getName() << "'s block" << endl;
			return 0;
		}
		cout << "To attack input 'a'" << endl;

		if (criticalChance() == true) {
			cout << "To get critical attack input 'c'" << endl;
			cc = 1;
		}
		if (defenseChance() == true) {
			cout << "To get shield input 'd'" << endl;
			dc = 1;
		}
		if (defenseChance() == true) {
			pc = 1;
		}
		cin >> action;
		if (action == 'a') {
			this->skill = new Attack();
			gap = this->skill->use(this->player);
			f = this->monster->getHealth() - gap;
		}
		else if (cc == 1 && action == 'c') {
			this->skill = new CriticalAttack();
			gap = this->skill->use(this->player);
			f = this->monster->getHealth() - gap;
		}
		else if (dc == 1 && action == 'd') {
			this->skill = new Block();
			this->player->setHealth(this->player->getHealth() + this->skill->use(this->player));
			f = this->monster->getHealth();
			cout << "Your health++: " << this->player->getHealth() << endl;
		}
		else {
			cout << "You were too kind to beat this creature, so you left it be" << endl;
			return 0;
		}
		if (f < this->monster->getHealth()) {
			(f < 0) ? monster->setHealth(0) : this->monster->setHealth(f);

			cout << "-" << gap << endl << "Monster's health : " << this->monster->getHealth() << endl;
		}
		return pc;
	}

	void win() {
		this->player->setCash(this->player->getCash() + this->monster->getCash());
		cout << "Your experience: +" << monster->getPlayerExperience() << endl;

		this->player->setExperience(this->monster->getPlayerExperience());
		cout << "Your cash: +" << monster->getCash() << endl;

	}
public:
	Engine(FunctionHelper* fH, NameHelper* nH)
	{
		this->fH = fH;
		this->nH = nH;

	}

	Shield* shieldGeneration() {
		int defense = this->fH->randomRes(4, 20);
		int price = defense * 200;

		return new Shield(this->nH->getShieldName(), defense, price);
	}

	Weapon* weaponGeneration() {

		int damage = this->fH->randomRes(4, 20);
		int price = damage * 200;

		return new Weapon(this->nH->getWeaponName(), damage, price);
	}


	Player* playerGeneration() {
		int power = 0, endurance = 0, agility = 0;
		int choice = 0;
		string name = "";


		cout << "Name:";
		cin >> name;
		cout << "Your role(barbarian - 1, tank - 2, thief - 3): ";
		cin >> choice;
		if (choice == 1) {
			power += 3;
		}
		else if (choice == 2) {
			endurance += 3;
		}
		else {
			agility += 3;
		}


		return new Player(35, 30, 1, power, agility, endurance, name, 50);
	}

	Monster* monsterGeneration(int level) {

		level = this->fH->randomRes(level - 1, level + 1);

		int health = 25;
		int energy = 25;
		int cash = 10;
		cash = this->fH->getCharacteristic(cash, level, 5);

		health = this->fH->getCharacteristic(health, level - 1, 10);
		energy = this->fH->getCharacteristic(energy, level, 10);
		int playerExperience = this->fH->getCharacteristic(0, level, 10);
		Monster* monster = new Monster(
			this->nH->getMonsterName(),
			health,
			energy,
			playerExperience,
			level);

		return monster;
	}
	int fight(Player* player, Monster* monster) {
		this->saveL = new SaveLoad();
		int f = 0;
		char choice;
		this->player = player;
		this->monster = monster;
		cout << endl << "Your opponnent's stats: " << this->monster->getName() << endl << "Level: " << this->monster->getLevel() << endl << "Health: " << this->monster->getHealth() << endl;
		cout << "Experience: " << this->monster->getPlayerExperience() << endl << "Cash: " << this->monster->getCash() << endl;
		cout << "You wanna fight?(y/n)";
		cin >> choice;

		if (choice == 't') {
			this->player->stats();
			return 0;
		}
		else if (choice == 's') {
			this->saveL->save(player);
			cout << "You saved your progress" << endl;
			return 0;
		}
		else if (choice != 'y') {
			return 0;
		}
		this->player->setEnergy(this->player->getEnergy() - this->monster->getLevel() * 2);


		int c = rand() % 2;
		bool pd = 0;
		bool md = 0;
		if (c == 1) {
			cout << "Your turn!" << endl;
			do {
				pd = playerTurn(md);
				if (this->monster->getHealth() <= 0) {
					cout << "You win!" << endl;
					win();
					break;
				}
				md = monsterTurn(pd);
				if (this->player->getHealth() <= 0) {
					cout << "You lose!" << endl;
					break;
				}
			} while (this->player->getHealth() > 0 || this->monster->getHealth() > 0);
		}
		else {
			cout << "Opponent's turn!" << endl;
			do {
				md = monsterTurn(pd);
				if (this->player->getHealth() <= 0) {
					cout << "You lose!" << endl;
					break;
				}
				pd = playerTurn(md);
				if (this->monster->getHealth() <= 0) {
					cout << "You win!" << endl;
					win();
					break;
				}
			} while ((this->player->getHealth() > 0 || this->monster->getHealth() > 0));
		}
		this->player->healthRegeneration();



	}
};