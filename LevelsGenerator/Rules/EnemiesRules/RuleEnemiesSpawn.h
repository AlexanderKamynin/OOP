#pragma once
#include "../../../EventsFactory/EnemiesEventFactory/EnemiesEventFactory.h"

template <EnemiesEventFactory::EnemyToCreate enemy,
	std::pair<int,int> health_range, std::pair<int,int> damage_range, std::pair<int,int> gold_range,
	int count>
class RuleEnemiesSpawn
{
public:
	void operator()(Field* field) {
		int current_count = 0;
		EnemiesEventFactory enemy_factory(field);
		//
		std::random_device random_device;
		std::default_random_engine generator(random_device());
		std::uniform_int_distribution<int> random_x(0, field->get_width() - 1);
		std::uniform_int_distribution<int> random_y(0, field->get_height() - 1);
		//
		while (true) {
			if (current_count == count) {
				break;
			}
			int x = random_x(generator);
			int y = random_y(generator);
			if (field->get_field()[y][x]->get_event() == nullptr
				&& field->get_player_position().first != x
				&& field->get_player_position().second != y) {
				current_count += 1;
				field->get_field()[y][x]->set_event(enemy_factory.createEnemy(enemy, health_range, damage_range, gold_range));
			}
		}
	}
};
