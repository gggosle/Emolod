#include <iostream>
#include <ctime>
#include <cmath>
#include <vector> 
using namespace std;

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
	string getName() {
		return this->name;
	}
};

class Shield : public Name {
private:
	int defense = 0;
	int price = 0;
public:
	Shield(string name, int shield, int price) : Name(name) {
		this->defense = shield;
	}
	void setPrice(int price) {
		this->price = price;
	}
	int getPrice() {
		return price;
	}
	void setDefense(int shield) {
		this->defense = shield;
	}
	int getDefense() {
		return defense;
	}
	void showShieldData() {
		cout << this->name << " defense value:  " << this->defense << " ------  price: " << this->price << endl;
	}
};
class Weapon : public Name {
	int damage = 0;
	int price = 0;
public:
	Weapon(string name, int damage, int price) :Name(name) {
		this->damage = damage;
	}
	void setPrice(int price) {
		this->price = price;
	}
	int getPrice() {
		return price;
	}
	void setDamage(int damage) {
		this->damage = damage;
	}
	int getDamage() {
		return damage;
	}
	void showWeaponData() {
		cout << this->name << " defense value:  " << this->damage << " ------  price: " << this->price << endl;
	}
};

class FunctionHelper {
public:
	int getCharacteristic(int ch, int level, int shift) {
		int min = 0;
		int max = 0;
		for (int i = 0; i <= level; i++) {
			min += shift;
			max += shift;
			ch += randomRes(min, max);
		}

		return ch;
	}
	int randomRes(int min, int max) {
		if (min > max) {
			int c = min;
			min = max;
			max = c;
		}

		return min + rand() % (max - min + 1);
	}
};

class Characteristics : public Name {
protected:
	int health = 0;
	int healthMax = 0;
	int energy = 0;
	int energyMax = 0;
	int level = 0;
	FunctionHelper* fH = NULL;

public:
	Characteristics(int health, int energy, string name, int level) : Name(name)
	{
		this->healthMax = health;
		this->health = health;
		this->energy = energy;
		this->energyMax = energy;
		this->level = level;
		this->fH = new FunctionHelper();
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
	int lvl = 0;
	int power = 0;
	float agility = 0;
	int endurance = 0;
	int experience = 0;
	int experienceMax = 0;
	int playerDamage = 0;
	int playerShield = 0;
	int cash = 0;
	Shield* shield = NULL;
	Weapon* weapon = NULL;
public:
	Player(int health, int energy, int level, int power, int agility, int endurance, string name, int cash) :Characteristics(health, energy, name, level)
	{
		this->cash = cash;
		this->power = power;
		this->agility = agility;
		this->endurance = endurance;
		this->experience = 0;
		this->experienceMax = 1000 * this->level;
	}
	int getLvl() {
		return lvl;
	}
	void setCash(int cash) {
		this->cash = cash;
	}
	int getCash() {
		return cash;
	}
	
	int healthRegeneration() {
		return this->health = this->healthMax;
	}

	void setShield(Shield* shield) {
		this->shield = shield;
	}

	Shield* getShield() {
		return this->shield;
	}

	void setWeapon(Weapon* weapon) {
		this->weapon = weapon;
	}

	Weapon* getWeapon() {
		return this->weapon;
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
	}
	void setExperience(int experience) {
		if (experience + this->experience > this->experienceMax) {
			this->experience = (experience + this->experience) - this->experienceMax;
			this->lvl += 1;
			this->agility += rand() % 5;
			this->power = rand() % 5;
			this->endurance = rand() % 5;
		}
		else {
			this->experience += experience;
		}
	}
	int getExperience() {
		return experience;
	}



	int generateDamage(int damage) {
		int playerDamage = (((damage + power) - 3) * this->fH->getCharacteristic(health, level, 10)) / 22;
		int critical = this->fH->getCharacteristic(health, level, 10);
		int percentage = 4;
		for (int i = 0; i < level; i++) {
			percentage += 4;
		}
		int criticalChance = agility * 100 / percentage;



		if ((1 + rand() % 10)/criticalChance == (1 + rand() % 10) / criticalChance) {
			return playerDamage = critical;
		}

		return playerDamage;
	}

	int generateShield(int defense) {
		return (((defense + endurance) - 3) * this->fH->getCharacteristic(health, level, 10)) / (20 + endurance);
	}

};

class Monster : public Characteristics {

private:
	int damage = 0;
	int shield = 0;
	int playerExperience = 0;
	int cash = 0;
public:
	Monster(string name, int health, int energy, int damage, int shield, int playerExperience, int level, int cash) : Characteristics(health, energy, name, level) {
		this->damage = damage;
		this->shield = shield;
		this->playerExperience = playerExperience;
	}
	void setCash(int cash) {
		this->cash = cash;
	}
	int getCash() {
		return cash;
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
	string weaponNames[5] = { "Sword", "Dagger", "Pike", "Axe", "Spear" };
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
	FunctionHelper* fH = NULL;
	NameHelper* nH = NULL;

public:
	Engine(FunctionHelper* fH, NameHelper* nH)
	{
		this->fH = fH;
		this->nH = nH;
	}

	Shield* shieldGeneration() {
		int price = 0;
		int defense = this->fH->randomRes(3, 20);
		for (int i = 0; i < defense; i++) {
			price += 20;
		}
		
		return new Shield(this->nH->getShieldName(), defense, price);
	}

	Weapon* weaponGeneration() {
		int price = 0;
		int damage = this->fH->randomRes(3, 20);
		for (int i = 0; i < damage; i++) {
			price += 20;
		}
		
		return new Weapon(this->nH->getWeaponName(), damage, price);
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

		level = this->fH->randomRes(level - 2, level+2);
		int health = 25;
		int energy = 25;
		int cash = 10;
		cash = this->fH->getCharacteristic(cash, level, 5);

		health = this->fH->getCharacteristic(health, level, 10);
		energy = this->fH->getCharacteristic(energy, level, 10);
		int damage = this->fH->getCharacteristic(health, level, 10) / (rand() % 10);
		int shield = this->fH->getCharacteristic(health, level, 10) / (rand() % 10);
		int playerExperience = this->fH->getCharacteristic(0, level, 10);
		Monster* monster = new Monster(
			this->nH->getMonsterName(),
			health,
			energy,
			damage,
			shield,
			playerExperience,
			level, cash);

		return monster;
	}
};


class Event {
private:
	int n = 0;
	Shield* shield = NULL;
	Weapon* weapon = NULL;
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
		if(this->player->getCash()>= 60){
		while(shiel.size()<3) {
			Shield* shield = this->engine->shieldGeneration();
			if (shield->getPrice() == this->player->getCash()) {
				shiel.push_back(shield);
			}
	   }
		while (weap.size() < 3) {
			Weapon* weapon = this->engine->weaponGeneration();
			if (weapon->getPrice() == this->player->getCash()) {
				weap.push_back(weapon);
			}
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
		(n > 3) ? this->player->setWeapon(weap[n - 4]) : this->player->setShield(shiel[n - 1]);

		}
		else {
			cout << "Right now we have nothing to offer you. See you next time" << endl;
		}
		
			
		
	}
	void bumpIntoMonster(){
		Monster* monster = this->engine->monsterGeneration(this->player->getLevel());
	}
	void improvement() {
		
		if (this->player->getLvl()> this->player->getLevel()){
			this->player->setLevel(this->player->getLvl());

			cout << "Congrats! You've reached new level!" << endl;
		}
	}
};

int main() {
	Engine* engine = new Engine(new FunctionHelper(), new NameHelper());

	Monster* mob = engine->monsterGeneration(1);
	Player* player = engine->playerGeneration();

	player->setWeapon(engine->weaponGeneration());
	
	return 1;
}
