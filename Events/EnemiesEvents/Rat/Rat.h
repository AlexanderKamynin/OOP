#pragma once
#include "../EnemiesEvents.h"
#include <iostream>


class Rat : public EnemiesEvents
{
public:
	Rat(Player* player) : EnemiesEvents(player) {};

	void React() override;

	void set_gold(int gold = 1) override;

	void set_passkey() override;

private:
	void set_stats();
};