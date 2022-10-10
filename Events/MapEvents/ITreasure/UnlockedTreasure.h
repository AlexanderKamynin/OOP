#pragma once
#include "ITreasure.h"
#include <iostream>


class UnlockedTreasure : public ITreasure
{
public:
	UnlockedTreasure(Player* player) : ITreasure(player) {};

	void set_gold_in_treasure(int gold) override;

	void React() override;
};

