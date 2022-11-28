#pragma once
#include "../../../Background/Field.h";
#include "../../../EventsFactory/EnemiesEventFactory/EnemiesEventFactory.h"

template <EnemiesEventFactory::EnemyToCreate enemy, int magic_number, int count>
class RuleEnemies
{
public:
	void operator()(Field* field) {
		int current_count = 0;
		EnemiesEventFactory enemies_factory(field);
		for (int y = 0; y < field->get_height(); y++) {
			for (int x = 0; x < field->get_width(); x++) {
				if (current_count == count) {
					return;
				}
				if ((x * magic_number) % field->get_width() == y + 3
					&& field->get_field()[y][x]->get_event() == nullptr
					&& (field->get_player_position().first != x)
					&& (field->get_player_position().second != y)) {
					current_count += 1;
					field->get_field()[y][x]->set_passability(true);
					field->get_field()[y][x]->set_event(enemies_factory.createEnemy(enemy));
				}
			}
		}
	}
};

