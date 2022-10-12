#pragma once
#include "../IEventFactory.h"
#include "../../Events/EnemiesEvents/Rat/Rat.h"
#include "../../Events/EnemiesEvents/Warrion/Warrion.h"
#include "../../Events/EnemiesEvents/Boss/Boss.h"

class EnemiesEventFactory : public IEventFactory {
public:
	EnemiesEventFactory(Player* player) : IEventFactory(player) {};

	IEvent* createRat(int gold = 10, int passkey = 0);

	IEvent* createWarrion(int gold = 30, int passkey = 0);

	IEvent* createBoss(int gold = 100, int passkey = 1);
};