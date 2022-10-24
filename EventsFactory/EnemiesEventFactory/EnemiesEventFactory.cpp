#include "EnemiesEventFactory.h"

IEvent* EnemiesEventFactory::createRat(int health, int damage, int gold, int passkey) {
	Rat* rat = new Rat(this->player, health, damage, gold, passkey);
	return rat;
}

IEvent* EnemiesEventFactory::createWarrion(int health, int damage, int gold, int passkey) {
	Warrion* warrion = new Warrion(this->player, health, damage, gold, passkey);
	return warrion;
}

IEvent* EnemiesEventFactory::createBoss(int health, int damage, int gold, int passkey) {
	Boss* boss = new Boss(this->player, health, damage, gold, passkey);
	return boss;
}