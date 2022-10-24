#pragma once
#include "ITreasure.h"
#include <iostream>


class LockedTreasure : public ITreasure
{
public:
	LockedTreasure(Player* player) : ITreasure(player) {};

	void set_gold_in_treasure(int gold) override;

	void React() override;

	bool is_one_time() override;

private:
	bool is_unlock();

	bool check_passkey();

	bool unlock = false;
};

