#pragma once
#include "../EnemiesEvents.h"
#include <iostream>


class Boss : public EnemiesEvents
{
public:
	Boss(Player* player, int health = 60, int damage = 15, int gold = 0, int passkey = 0) : EnemiesEvents(player, health, damage, gold, passkey) {};

	void React() override;

	bool is_one_time() override;
};