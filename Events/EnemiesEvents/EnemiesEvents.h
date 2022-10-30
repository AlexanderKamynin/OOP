#pragma once
#include "../IEvent.h"
#include "../../Player/Player.h"
#include "../../EnumClass.h"
#include <iostream>

class EnemiesEvents : public IEvent
{
public:
	EnemiesEvents(Player* player, int health, int damage, int gold = 0, int passkey = 0);

	bool is_dead();

	virtual ~EnemiesEvents() = 0 {};
protected:
	Player* player;
	int damage;
	int health;
	int gold;
	int passkey;

	void preview_battle();
	void battle();
	void before_battle(bool battle_result);
};

