#pragma once
#include "Player.h"
class SkillInterface {
public:
	virtual int use(Player* player) = 0;
};

