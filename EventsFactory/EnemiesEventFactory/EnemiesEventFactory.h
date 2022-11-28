#pragma once
#include "../IEventFactory.h"
#include "../../Events/EnemiesEvents/Rat/Rat.h"
#include "../../Events/EnemiesEvents/Warrion/Warrion.h"
#include "../../Events/EnemiesEvents/Boss/Boss.h"

class EnemiesEventFactory : public IEventFactory {
public:
	EnemiesEventFactory(Field* player) : IEventFactory(field) {};

	IEvent* createRat(int health = 20, int damage = 3, int gold = 10, int passkey = 0);

	IEvent* createWarrion(int health = 40, int damage = 5, int gold = 30, int passkey = 0);

	IEvent* createBoss(int health = 50, int damage = 10, int gold = 100, int passkey = 0);
};