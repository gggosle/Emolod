#pragma once
#include "SkillInterface.h"

class Attack : public SkillInterface {
	int use(Player* player) override {
		player->setDamage(player->getWeapon()->getDamage());
		return player->getDamage();
	}
};

