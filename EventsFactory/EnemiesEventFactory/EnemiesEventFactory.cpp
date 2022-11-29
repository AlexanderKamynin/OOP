#include "EnemiesEventFactory.h"


IEvent* EnemiesEventFactory::createEnemy(EnemyToCreate enemy_to_create, std::pair<int, int> health_range, std::pair<int, int> damage_range, std::pair<int, int> gold_range)
{
	IEvent* new_enemy = nullptr;
	switch (enemy_to_create) {
	case EnemyToCreate::RatEnemy: {
		new_enemy = this->createConcreteEnemy<Rat>(health_range, damage_range, gold_range);
		break;
	}
	case EnemyToCreate::WarrionEnemy: {
		new_enemy = this->createConcreteEnemy<Warrion>(health_range, damage_range, gold_range);
		break;
	}
	case EnemyToCreate::BossEnemy: {
		new_enemy = this->createConcreteEnemy<Boss>(health_range, damage_range, gold_range);
		break;
	}
	}
	return new_enemy;
}
