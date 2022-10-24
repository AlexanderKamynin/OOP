#pragma once
#include "../EnemiesEvents.h"
#include <iostream>


class Warrion : public EnemiesEvents
{
public:
	Warrion(Player* player, int health = 40, int damage = 5, int gold = 0, int passkey = 0) : EnemiesEvents(player, health, damage, gold, passkey) {};

	void React() override;

	bool is_one_time() override;
};

