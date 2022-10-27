#pragma once
#include "SkillInterface.h"

class Block : public SkillInterface {
	int use(Player* player) override {
		return player->getDefense(player->getShield()->getDefense());
	}
};

