#pragma once
#include "../EnemiesEvents.h"
#include <iostream>


class Boss : public EnemiesEvents
{
public:
	Boss(Player* player) : EnemiesEvents(player) {};

	void React() override;

	void set_gold(int gold = 1) override;

	void set_passkey(int passkey = 1) override;

private:
	void set_stats() override;
};