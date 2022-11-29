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

	IEvent* createEnemy(EnemyToCreate enemy_to_create, std::pair<int,int> health_range, std::pair<int,int> damage_range, std::pair<int,int> gold_range);
private:
	template <class Enemy>
	IEvent* createConcreteEnemy(std::pair<int, int> health_range, std::pair<int, int> damage_range, std::pair<int, int> gold_range) {
		//
		std::random_device random_device;
		std::default_random_engine generator(random_device());
		//
		std::uniform_int_distribution<int> random_health(
			std::min(health_range.first, health_range.second),
			std::max(health_range.first, health_range.second));
		std::uniform_int_distribution<int> random_damage(
			std::min(damage_range.first, damage_range.second),
			std::max(damage_range.first, damage_range.second));
		std::uniform_int_distribution<int> random_gold(
			std::min(gold_range.first, gold_range.second),
			std::max(gold_range.first, gold_range.second));
		std::uniform_int_distribution<int> random_passkey(0, 1);
		return new Enemy(
			this->field->get_player(),
			random_health(generator),
			random_damage(generator),
			random_gold(generator),
			random_passkey(generator)
		);
	};
};

