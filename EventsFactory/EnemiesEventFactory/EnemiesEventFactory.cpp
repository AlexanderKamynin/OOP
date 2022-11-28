#include "EnemiesEventFactory.h"


IEvent* EnemiesEventFactory::createEnemy(EnemyToCreate enemy_to_create)
{
	IEvent* new_enemy = nullptr;
	switch (enemy_to_create) {
		case EnemyToCreate::RatEnemy: {
			new_enemy = this->createRat();
			break;
		}
		case EnemyToCreate::WarrionEnemy: {
			new_enemy = this->createWarrion();
			break;
		}
		case EnemyToCreate::BossEnemy: {
			new_enemy = this->createBoss();
			break;
		}
	}
	return new_enemy;
}

IEvent* EnemiesEventFactory::createRat()
{
	//
	std::random_device random_device;
	std::default_random_engine generator(random_device());
	//
	std::uniform_int_distribution<int> random_health(10, 20);
	std::uniform_int_distribution<int> random_damage(1, 3);
	std::uniform_int_distribution<int> random_gold(5, 50);
	std::uniform_int_distribution<int> random_passkey(0, 1);
	return new Rat(
		this->field->get_player(),
		random_health(generator),
		random_damage(generator),
		random_gold(generator),
		random_passkey(generator)
	);
}