#pragma once
#include "Monster.h"
#include "Player.h"
#include "NameHelper.h"

class Engine {
private:
	Monster* monster = NULL;
	Player* player = NULL;
	FunctionHelper* fH = NULL;
	NameHelper* nH = NULL;
	Event* event = NULL;
	void monsterTurn() {
		int gap = 0;
		int f = (this->player->getHealth() + this->player->generateShield(this->player->getShield()->getDefense())) - this->monster->generateDamage();
		if (f < this->player->getHealth()) {
			gap = this->player->getHealth() - f;
			this->player->setHealth(f);
		}
		cout << "-" << gap << endl << "Your health: " << this->player->getHealth() << endl;
	}
	void playerTurn() {
		int gap = 0;
		int f = (this->monster->getHealth() + this->monster->generateShield()) - this->player->generateDamage(this->player->getWeapon()->getDamage());
		if (f < this->monster->getHealth()) {
			gap = this->monster->getHealth() - f;
			this->monster->setHealth(f);
		}
		cout << "-" << gap << endl << "Monster's health : " << this->player->getHealth() << endl;
	}
	void win() {
		this->player->setCash(this->player->getCash() + this->monster->getCash());
		this->player->setExperience(this->monster->getPlayerExperience());
	}
public:
	Engine(FunctionHelper* fH, NameHelper* nH)
	{
		this->fH = fH;
		this->nH = nH;

	}

	Shield* shieldGeneration() {
		int price = 0;
		int defense = this->fH->randomRes(3, 20);

		return new Shield(this->nH->getShieldName(), defense, defense * 20);
	}

	Weapon* weaponGeneration() {
		int price = 0;
		int damage = this->fH->randomRes(3, 20);


		return new Weapon(this->nH->getWeaponName(), damage, damage * 20);
	}


	Player* playerGeneration() {
		int power = 0, endurance = 0, agility = 0;
		int choice = 0;
		string name = "";


		cout << "Name:";
		cin >> name;
		cout << endl << "Your role(barbarian - 1, tank - 2, thief - 3): ";
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


		return new Player(30, 30, 1, power, agility, endurance, name, 50);
	}

	Monster* monsterGeneration(int level) {

		level = this->fH->randomRes(level - 2, level + 2);
		int health = 25;
		int energy = 25;
		int cash = 10;
		cash = this->fH->getCharacteristic(cash, level, 5);

		health = this->fH->getCharacteristic(health, level, 10);
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
	int fight(Player* player, Event* event) {
		this->event = event;
		char choice;
		this->player = player;
		this->event->bumpIntoMonster();
		cout << "Your opponnent's stats: " << endl << "Level: " << this->monster->getLevel() << endl << "Health: " << this->monster->getHealth() << endl;
		cout << "Experience: " << this->monster->getPlayerExperience() << endl << "Cash: " << this->monster->getCash() << endl;
		cout << "You wanna fight?(y/n)";
		cin >> choice;
		if (choice == 'n') {
			return 0;
		}
		this->player->setEnergy(this->player->getEnergy() - this->monster->getLevel() * 2);

		int f = 0;
		int c = rand() % 2;
		if (c == 0) {
			while (this->player->getHealth() > 0 || this->monster->getHealth() > 0) {
				playerTurn();
				if (f == 0) {
					cout << "You win!" << endl;
					win();
					break;
				}
				monsterTurn();
				if (f == 0) {
					cout << "You lose!" << endl;
					break;
				}
			}
		}
		else {
			while (this->player->getHealth() > 0 || this->monster->getHealth() > 0) {
				monsterTurn();
				if (f == 0) {
					cout << "You lose!" << endl;
					break;
				}
				playerTurn();
				if (f == 0) {
					cout << "You win!" << endl;
					win();
					break;
				}
			}
		}
		this->player->healthRegeneration();
	}
};

