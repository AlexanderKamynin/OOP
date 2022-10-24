#pragma once
#include "../EnemiesEvents.h"
#include <iostream>


class Rat : public EnemiesEvents
{
public:
	Rat(Player* player, int health = 20, int damage = 3, int gold = 0, int passkey = 0) : EnemiesEvents(player, health, damage, gold, passkey) {};

	void React() override;
	
	bool is_one_time() override;
};