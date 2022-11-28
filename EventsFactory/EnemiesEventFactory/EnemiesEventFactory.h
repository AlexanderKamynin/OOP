#pragma once
#include "../IEventFactory.h"
#include "../../Events/EnemiesEvents/Rat/Rat.h"
#include "../../Events/EnemiesEvents/Warrion/Warrion.h"
#include "../../Events/EnemiesEvents/Boss/Boss.h"


class EnemiesEventFactory : public IEventFactory {
public:
	EnemiesEventFactory(Field* field) : IEventFactory(field) {};

	enum EnemyToCreate {
		RatEnemy,
		WarrionEnemy,
		BossEnemy
	};

	IEvent* createEnemy(EnemyToCreate enemy_to_create);
private:
	template <class Enemy, std::pair health_range, std::pair damage_range, std::pair gold_range>
	IEvent* createConcreteEnemy();
};


template <class Enemy, std::pair health_range, std::pair damage_range, std::pair gold_range>
inline IEvent* EnemiesEventFactory::createConcreteEnemy()
{
	//
	std::random_device random_device;
	std::default_random_engine generator(random_device());
	//
	std::uniform_int_distribution<int> random_health(
		std::min(health_range.first, health_range.second),
		std::max(health_range.first, health_range.second);
	std::uniform_int_distribution<int> random_damage(
		std::min(damage_range.first, damageg_range.second),
		std::max(damage_range.first, damage_range.second);
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
