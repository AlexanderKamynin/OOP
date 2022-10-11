#pragma once
#include "../IEvent.h"
#include "../../Player/Player.h"
#include <iostream>

class EnemiesEvents : public IEvent
{
public:
	EnemiesEvents(Player* player);

	virtual void set_gold(int gold = 1) = 0;

	virtual void set_passkey() = 0;

	bool is_dead();
protected:
	Player* player;
	int damage;
	int health;
	int gold;
	int passkey;

	void preview_battle();
	void battle();
	void before_battle(bool battle_result);
	virtual void set_stats() = 0;
};

