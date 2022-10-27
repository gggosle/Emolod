#pragma once
#include "MSkillInterface.h"
class MAttack : public MSkillInterface {
	int use(Monster* monster) override {
		return monster->getDamage();
	}
};
