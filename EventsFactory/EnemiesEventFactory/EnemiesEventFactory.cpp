#include "EnemiesEventFactory.h"

IEvent* EnemiesEventFactory::createRat(int gold, int passkey) {
	Rat* rat = new Rat(this->player);
	rat->set_gold(gold);
	rat->set_passkey(passkey);
	return rat;
}

IEvent* EnemiesEventFactory::createWarrion(int gold, int passkey) {
	Warrion* warrion = new Warrion(this->player);
	warrion->set_gold(gold);
	warrion->set_passkey(passkey);
	return warrion;
}

IEvent* EnemiesEventFactory::createBoss(int gold, int passkey) {
	Boss* boss = new Boss(this->player);
	boss->set_gold(gold);
	boss->set_passkey(passkey);
	return boss;
}