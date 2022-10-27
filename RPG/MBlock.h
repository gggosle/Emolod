#pragma once
#include "MSkillInterface.h"
class MBlock : public MSkillInterface {
	int use(Monster* monster) override {
		return monster->getDefense();
	}
};
