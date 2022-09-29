#include <iostream>
#include <ctime>
#include <cmath>
#include <vector> 
using namespace std;
int getCharacteristic(int characteristic, int level, int shift) {
	int characteristic = 0;
	int min = 0;
	int max = 0;
	for (int i = 0; i <= level; i++) {
		min += shift;
		max += shift;
		characteristic += randomRes(min, max);
	}

	return characteristic;
}
int randomRes(int min, int max) {
	if (min > max) {
		int c = min;
		min = max;
		max = c;
	}

	return min + rand() % (max - min + 1);
}

class Name {
protected:
	string name = "";
public:
	Name(string name) {
		this->name = name;
	}
	void setName(string name) {
		this->name = name;
	}

};

class Characteristics : public Name {
protected:
	int health = 0;
	int healthMax = 0;
	int energy = 0;
	int energyMax = 0;
	string name = "";
	int level = 0;
public:
	Characteristics(int health, int energy, string name, int level): Name(name)
	{
		this->healthMax = health;
		this->health = health;
		this->energy = energy;
		this->energyMax = energy;
		this->name = name;
		this->level = level;
	}

	void setHealth(int health) {
		if (health > this->healthMax) {
			this->health = this->healthMax;
		}
		else {
			this->health = health;
		}
	}
	int getHealth() {
		return health;
	}
	void setEnergy(int energy) {
		if (energy > this->energyMax) {
			this->energy = this->energyMax;
		}
		else {
			this->energy = energy;
		}
	}
	int getEnergy() {
		return energy;
	}void setName(int name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
	void setLevel(int level) {
		this->level = level;
	}
	int getLevel() {
		return level;
	}
};
class Player : public Characteristics {
private:
	int power = 0;
	int agility = 0;
	int endurance = 0;
	int experience = 0;
	int experienceMax = 0;
	int playerDamage = 0;
	int playerShield = 0;
	Shield* shield;
	Weapon* weapon;
public:
	Player(int health, int energy, int level, int power, int agility, int endurance, int experience, string name) :Characteristics(health, energy, name, level)
	{
		this->power = power;
		this->agility = agility;
		this->endurance = endurance;
		this->experience = experience;
		this->experienceMax = experience;
	}
	void setPower(int power) {
		this->power = power;
	}
	int getPower() {
		return power;
	}void setAgility(int agility) {
		this->agility = agility;
	}int getAgility() {
		return agility;
	}void setEndurance(int endurance) {
		this->endurance = endurance;
	}int getEndurance() {
		return endurance;
	}void setExperience(int experience) {
		if (experience > this->experienceMax) {
			this->experience = 0;
			this->level += 1;
		}
		else {
			this->experience = experience;
		}
	}
	int getExperience() {
		return experience;
	}

	int generateDamage(int damage) {
		playerDamage = (((damage + power)-3)* getCharacteristic(health, level, 10))/22;
		int critical = getCharacteristic(health, level, 10);
		int quant_of_critical = rand() % agility;

	}
	int generateShield(int defense) {
		playerShield = (((defense + endurance)-3) * getCharacteristic(health, level, 10)) / 22;


	}

};



class Monster : public Characteristics {

private:

	int damage = 0;
	int shield = 0;
	int playerExperience = 0;
public:
	Monster(string name, int health, int energy, int damage, int shield, int playerExperience, int level) : Characteristics(health, energy, name, level) {
		this->damage = damage;
		this->shield = shield;
		this->playerExperience = playerExperience;
	}
	void setDamage(int damage) {
		this->damage = damage;
	}
	int getDamage() {
		return damage;
	}void setShield(int shield) {
		this->shield = shield;
	}
	int getShield() {
		return shield;
	}
	void setPlayerExperience(int playerExperience) {
		this->playerExperience = playerExperience;
	}
	int getPlayerExperience() {
		return playerExperience;
	}

};

class NameHelper {
private:
	string monsterNames[10] = { "Bogeyman","Vampire","Zombie", "Hydra","Chimera","Yeti","Dragon","Basilisk","Werewolf", "Gorgon" };
	string shieldNames[5] = { "Viking Shield", "Bouche Shield","Buckler Shield","Heater Shield","Kite Shield" };
	string weaponNames[5] = { "Sword", "Dagger", "Pike", "Ax", "Spear" };
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

class Engine {
private:
	/*int getCharacteristic(int characteristic, int level, int shift) {
		int characteristic = 0;
		int min = 0;
		int max = 0;
		for (int i = 0; i <= level; i++) {
			min += shift;
			max += shift;
			characteristic += randomRes(min, max);
		}

		return characteristic;
	}

	int randomRes(int min, int max) {
		if (min > max) {
			int c = min;
			min = max;
			max = c;
		}

		return min + rand() % (max - min + 1);
	}*/



public:
	Engine() {};

	Shield* shieldGeneration(string name) {
		int defense = randomRes(3, 20);
		Shield* shield = new Shield(name, defense);
		return shield;
	}
	Weapon* weaponGeneration(string name) {
		int damage = randomRes(3, 20);
		Weapon* weapon = new Weapon(name, damage);
		return weapon;
	}

	Player* playerGeneration(string name) {
		int power = 0, endurance = 0, agility = 0;
		int choice = 0;


		cout << "Name:";
		cin >> name;
		cout << endl << "Your role(barbarian - 1, tank - 2, thief - 3): ";
		cin >> choice;
		if (choice == 1) {
			power += 5;
		}
		else if (choice == 2) {
			endurance += 5;
		}
		else {
			agility += 5;
		}
		

		return new Player(30, 30, 1, power, agility, endurance, 0, name);
	}

	Monster* monsterGeneration(string name, int level) {

		level += rand() % 2 + 1;
		int health = 25;
		int energy = 25;

		health = getCharacteristic(health, level, 10);
		energy = getCharacteristic(energy, level, 10);
		int damage = getCharacteristic(health, level, 10) /(rand()%10);
		int shield = getCharacteristic(health, level, 10) / (rand() % 10);
		int playerExperience = getCharacteristic(0, level, 10);
		Monster* monster = new Monster(
			name,
			health,
			energy,
			damage,
			shield,
			playerExperience,
			level);

		return monster;
	}
};
class Shield : public Name {
private:
	int defense = 0;
public:
	Shield(string name, int shield) : Name(name) {
		this->defense = shield;
	}
	void setDefense(int shield) {
		this->defense = shield;
	}
	int getDefense() {
		return defense;
	}
};
class Weapon : public Name {
	int damage = 0;
public:
	Weapon(string name, int damage) :Name(name) {
		this->damage = damage;
	}
	void setDamage(int damage) {
		this->damage = damage;
	}
	int getDamage() {
		return damage;
	}
};


int main() {
	Engine* engine = new Engine();
	NameHelper* nameHelper = new NameHelper();

	Monster* mob = engine->monsterGeneration(nameHelper->getMonsterName(), 1);
	Weapon* weapon = engine->weaponGeneration(nameHelper->getWeaponName());
	return 1;
}


