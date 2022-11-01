#pragma once
#include "SkillInterface.h"

class Block : public SkillInterface {

public:
	int use(Player* player) override {
		return player->getDefense(player->getShield()->getDefense());
	}
};

