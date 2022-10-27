#pragma once
#include "SkillInterface.h"

class CriticalAttack : public SkillInterface {
public:
	int use(Player* player) override {
		player->setCriticalDamage(player->getWeapon()->getDamage());
		return player->getDamage();
	}
};
