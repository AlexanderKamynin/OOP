#pragma once
#include "../EnemiesEvents.h"
#include <iostream>


class Warrion : public EnemiesEvents
{
public:
	Warrion(Player* player) : EnemiesEvents(player) {};

	void React() override;

	void set_gold(int gold = 1) override;

	void set_passkey() override;

private:
	void set_stats() override;
};

