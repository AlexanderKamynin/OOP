#pragma once
#include "../EnemiesEvents.h"
#include <iostream>


class Rat : public EnemiesEvents
{
public:
	Rat(Player* player) : EnemiesEvents(player) {};

	void React() override;

	void set_gold(int gold = 1) override;

	void set_passkey(int passkey = 1) override;

private:
	void set_stats() override;
};