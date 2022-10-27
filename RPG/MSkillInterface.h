#pragma once

#include "Monster.h"
class MSkillInterface {

public:
	virtual int use(Monster* monster) = 0;
};
